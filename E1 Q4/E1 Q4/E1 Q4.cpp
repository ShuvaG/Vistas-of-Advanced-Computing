//E1 Q4
#include <iostream>
using namespace std;

int main()
{
	int *pt, c;
	c = 10;
	pt = &c;

	cout << "The value of c (int variable) is: " << c << endl;
	cout << "The vallue of *pt (pointer/value) is: " << *pt << endl;
	cout << "The value of &c (address) is: " << &c << endl;
	cout << "The value of pt (pointer/address) is: " << pt << endl << endl;
	cout << "So c=*pt, and &c=pt." << endl << endl;

	cout << "--------------If we change the value of c--------------" << endl;
	c = 5;
	cout << "The value of c(new): " << c << endl;
	cout << "The value of the adress is the same (pt): " << pt << endl;
	cout << "The value that pointer hold changes (*pt new): " << *pt << endl;

	system("PAUSE");
	return 0;
}