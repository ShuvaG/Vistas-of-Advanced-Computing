// Dr. Prosperetti's Coding Assignment 
//* PLEASE USE CODECHIEF TO EXECUTE *//

#include <iostream>
#include <math.h>
using namespace std;

double cosfunc(double x)
{
	double fx = cos(x) - x;
	return fx;
}

double cosderiv(double x)
{
	double fx1 = -sin(x) - 1;
	return fx1;
}

double expfunc(double x)
{
	double fx = exp(-x) - x;
	return fx;
}

double expderiv(double x)
{
	double fx1 = -exp(-x) - 1;
	return fx1;
}

int main()
{
	const double tolerance = pow(10,-10);
	int k;
	const int terms = 10000;
	double x[terms];
	double y[terms];
	double expfinalAnswer = 0;
	double cosfinalAnswer = 0;

	cout << "What number do you want to start with (for cos and exp)? " << endl;
	cin >> k;

	x[0] = k;
	y[0] = k;


	for (int i = 0; i < terms; i++)
	{
		x[i + 1] = x[i] - expfunc(x[i]) / expderiv(x[i]);
		expfinalAnswer = x[i + 1];
		cout << expfinalAnswer << endl;
		if (abs(((x[i + 1] - x[i])) / x[i + 1]) < tolerance) break;
	}
	
	cout << endl;

	for (int i = 0; i < terms; i++)
	{
		y[i + 1] = y[i] - cosfunc(y[i]) / cosderiv(y[i]);
		cosfinalAnswer = y[i + 1];
		cout << cosfinalAnswer << endl;
		if (abs(((y[i + 1] - y[i])) / y[i + 1]) < tolerance) break;
	}

	cout << "The root for e^(-x)-x  is = " << expfinalAnswer << endl;
	cout << "The root for cos(x)-x  is = " << cosfinalAnswer << endl;

	int j;
	cin >> j;
	return 0;
}