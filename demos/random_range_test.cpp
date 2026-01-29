#include <iostream>
#include "../random_range.h"

using namespace std;

int main(void)
{
	srandom((unsigned)time(NULL));

	cout << "running random_range(3) 50 times..." << endl;
	for(int i=0; i<50; i++)
	{
		cout << random_range(3) << " ";
	}
	cout << endl;

	return 0;
}
