#include <iostream>
#include "miller-rabin.h"

using namespace std;

int main(int argc, char **argv)
{
	unsigned in_n;
	int in_k;

	cout << "Enter prime to test: ";
	cin >> in_n;

	// 1 is a special case; it is explicitly NOT prime by definition
	if(in_n ==1)
	{
		cout << "1 is NOT prime, by definition" << endl;
		return 1;
	}
	// 2 is a special case, the only even/non-odd prime number
	if(in_n == 2)
	{
		cout << "2 is (the only even) prime" << endl;
		return 0;
	}
	// categorically exclude even numbers as not prime
	if((in_n & 1) == 0)
	{
//		cout << "BAD INPUT: Integer n to test must be > 2 and odd; all even numbers are divisible by 2, and 2 itself is the smallest (and the only even) prime" << endl;
		cout << in_n << " is NOT prime; all even numbers are divisible by 2";
		return 1;
	}

	cout << "k (rounds)?: ";
	cin >> in_k;

	bool result = primalityTest_MillerRabin(in_n, in_k);

	if(result)
	{
		cout << in_n << " is *probably* prime" << endl;
		return 0;
	}
	else
	{
		cout << in_n << " is composite/NOT prime" << endl;
		return 1;
	}
}
