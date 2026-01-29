#include <cstdlib>
#include <ctime>
#include "miller-rabin.h"
#include "random_range.h"
#include "msb/mostsignificantbit.h"

/* returns false if integer is NOT ptime, returns true if it is */
bool primalityTest_MillerRabin(unsigned n, unsigned trials)
{
	srandom((unsigned)time(NULL));

	unsigned a;

	for(unsigned i=1; i <= trials; i++)
	{
		a = random_range(n-2) + 1;

		if(witness(a, n))
		{
			return false;
		}
	}

	return true;
}

bool witness(unsigned radix, unsigned n)
{
	unsigned u = n-1;
	int t = 0;

	while((u & 0x1) == 0x0)
	{
		u = u >> 1;
		t++;
	}

	unsigned x = 1;
	unsigned mask = mostSignificantBit_64(u);

	while(mask)
	{
		x = (x*x) % n;
		if(u & mask)
		{
			x = (x*radix) % n;
		}
		mask >>= 1;
	}

	unsigned w;
	for(int i=1; i <= t; i++)
	{
		w = x;
		x = (w*w) % n;
		if(x == 1 && w != 1 && w != n-1)
		{
			return true;
		}
	}

	return x != 1;
}
