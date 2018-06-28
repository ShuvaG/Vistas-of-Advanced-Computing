// Assignment 2B - Round Function

#include <iostream>
using namespace std;

float roundoff(float number, int x, int type)
{
	float newNumber, bigger_number, finalAnswer, roundofferror, multiplier;
	string up, down, integer;
	finalAnswer = 0;
	multiplier = pow(10, x);
	newNumber = number * multiplier;
	switch (type)
	{
	case 1:
		bigger_number = ceilf(newNumber);
		finalAnswer = bigger_number / multiplier;
		cout << "The rounded number is: " << finalAnswer << endl;
		roundofferror = abs((number - finalAnswer) / number);
		cout << "The round-off error: " << roundofferror << endl;
		break;
	case 2:
		bigger_number = floorf(newNumber);
		finalAnswer = bigger_number / multiplier;
		cout << "The rounded number is: " << finalAnswer << endl;
		roundofferror = abs((number - finalAnswer) / number);
		cout << "The round-off error: " << roundofferror << endl;
		break;
	case 3:
		bigger_number = round(newNumber);
		finalAnswer = bigger_number / multiplier;
		cout << "The rounded number is: " << finalAnswer << endl;
		roundofferror = abs((number - finalAnswer) / number);
		cout << "The round-off error: " << roundofferror << endl;
		break;
	}

	return finalAnswer;
}

/*int main ()
{
float n, ans, m;
int type;
cout << "Enter number: " << endl;
cin >> n;
cout << "How many decimal places do you want?" << endl;
cin >> m;
cout << "Do you want to round up (1), down (2), or to the nearest integer (3)?" << endl;
cin >> type;
ans = roundoff(n,m,type);
int j;
cin >> j;

return 0;
}*/

int main()
{
	float a, b, c, d, e, f, x, y, ansx, ansy;
	int m, type;
	cout << "The equation is ax+by =c" << endl;
	cout << "The equation is dx+ey=f" << endl;
	cout << "Enter value for a: ";
	cin >> a;
	cout << "Enter value for b: ";
	cin >> b;
	cout << "Enter value for c: ";
	cin >> c;
	cout << "Enter value for d: ";
	cin >> d;
	cout << "Enter value for e: ";
	cin >> e;
	cout << "Enter value for f: ";
	cin >> f;

	y = (f*a - d * c) / (a*e - d * b);
	x = (c - b * y) / a;

	cout << "How many decimal places do you want?" << endl;
	cin >> m;
	cout << "Do you want to round up (1), down (2), or to the nearest integer (3)?" << endl;
	cin >> type;
	ansx = roundoff(x, m, type);
	ansy = roundoff(y, m, type);

	cout << "x=" << ansx << endl;
	cout << "y=" << ansy;
	int j;
	cin >> j;
	return 0;
}