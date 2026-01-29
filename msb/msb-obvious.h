#ifndef _MSB_OBVIOUS_H_
#define _MSB_OBVIOUS_H_

unsigned msbDumb(unsigned long v)
{
	unsigned r = 0; // r will be lg(v)

	while(v >>= 1) // unroll for more speed...
	{
		r++;
	}

	return r;
}

#endif
