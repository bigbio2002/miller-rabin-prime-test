#ifndef _RUSSIANPEASANT_H_
#define _RUSSIANPEASANT_H_

template <class SemiGroupElement, class Integer>
SemiGroupElement exponentiate3(SemiGroupElement x, Integer n)
{
	while((n & 1) == 0)
	{
		x = x*x;
		n >>= 1;
	}

	SemiGroupElement P = x;
	n >>= 1;
	while(n > 0)
	{
		x = x*x;
		if((n & 1) != 0)
			P = P*x;
		n >>= 1;
	}

	return P;
}

#endif
