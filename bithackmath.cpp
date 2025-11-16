unsigned int modulus_bh1()
{
	const unsigned int numerator;
	const unsigned int s;
	const unsigned int d = 1U << s;
	unsigned int mod_result;

	mod_result = numerator & (d - 1);

	return mod_result;
}

unsigned int modulus_bh2()
{
	unsigned int numerator;
	const unsigned int s;	// s > 0
	const unsigned int d = (1 << s) - 1;	// d can be 1, 3, 7, 15, 31, ...
	unsigned int mod_result;	// m = numerator % d

	for(mod_result=numerator;numerator>d;numerator=mod_result)
	{
		for(mod_result=0;numerator;numerator>>=s)
		{
			mod_result += numerator % d;
		}
	}
	// now m is a value from 0 thru d, but this is mod. div.,
	// m must = 0 when it is d
	mod_result = mod_result == d ? 0 : mod_result;

	return mod_result;
}
