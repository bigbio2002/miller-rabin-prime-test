#include <cstdlib>
#include <ctime>
#include "miller-rabin.h"
#include "random_range.h"
#include "msb/msb.h"

/* returns false if integer is NOT ptime, returns true if it is */
bool primalityTest_MillerRabin(uint64_t n, uint64_t trials)
{
	uint64_t a;

	for(int i=1; i <= trials; i++)
	{
		a = random_range(n-2) + 1;

		if(witness(a, n))
		{
			// not prime
			return false;
		}
	}

	// not not-prime
	return true;
}

bool witness(uint64_t radix, uint64_t n)
{
	uint64_t u = n-1;
	int t = 0;

	while((u & 0x1) == 0x0)
	{
		u = u >> 1;
		t++;
	}

	uint64_t x = 1;
	uint64_t mask = msb64(u);

	while(mask)
	{
		x = (x*x) % n;
		if(u & mask)
		{
			x = (x*radix) % n;
		}
		mask >>= 1;
	}

	uint64_t w;
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
