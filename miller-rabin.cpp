#include <iostream>

int main(int argc, char *argv)
{
	unsigned int input_n, input_k;

	cout >> "enter prime to test: "
	cin >> input_n;
	if(input_n <= 2 || (input_n & 1) == 0)
	{
		cout << "BAD INPUT: Integer n to test must be > 2 and odd; all even numbers are divisible by 2, and 2 itself is the smallest (and the only even) prime" << endl;
		return 1;
	}
	cout >> "k (rounds)?: "
	cin >> input_k;

	return 0;
}
