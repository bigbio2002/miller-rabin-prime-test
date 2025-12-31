#include <stdlib.h>
#include <time.h>
#include "miller-rabin.h"
#include "rand_range.h"
#include "msb3.h"

bool primalityTest_MillerRabin(unsigned n, unsigned trials)
{
	srandom(time(NULL));

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

bool witness(unsigned a, unsigned n)
{
	unsigned t = 0;
	unsigned u = n-1;

	while((u & 0x1) == 0)
	{
		u = u >> 1;
		t++;
	}

	unsigned x = 1;
	unsigned mask;
	mask = msb32(u);

	while(mask)
	{
		x = (x*x) % n;
		if(u & mask)
		{
			x = (x*a) % n;
		}
		mask = mask >> 1;
	}

	unsigned w;
	for(unsigned i=1; i <= t; i++)
	{
		w = x;
		x = (w*w) % n;
		if(x == 1 && w != 1 && w != n-1)
		{
			return true;
		}
	}

	return (x != 1);
}
