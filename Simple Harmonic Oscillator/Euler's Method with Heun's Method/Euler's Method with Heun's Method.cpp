// Euler's Method with Heun's Method

#include <iostream>
#include <math.h>
using namespace std;

/*void errorfunction(double &u1step, double &u2step, double &h)
{
	double error, tolerance1,tolerance2;
	tolerance1 = .05;
	tolerance2 = pow(10, -4);


	error = abs((u1step - u2step) / u2step);
	if (error < tolerance1)
	{
		h *= 2;
	}
	if (error > tolerance2)
	{
		u2step = u1step;
		h /= 2;
	}
}*/
 
double HeunsMetu1(double v, double k, double x, double h, double t)
{
	double vstar=0;
	for (double i=0; i<=t; i=i+h)
		vstar = v + (-k * k*x)*h; //Approximates value at v(n+1)
	return vstar;
}
double HeunsMetu2(double x, double v, double h, double t)
{
	double xstar=0;
	for (double i=0; i<t; i=i+h)
	xstar = x + v * h; //Approximates value at x(n+1)
	return xstar;
}

int main()
{
	double v, k, x, h, Xo, Vo, t, x1,v1;
	double pi = 3.14159;

	// (dx/dt) f1=v
	// (dv/dt) f2=-k^2*x

	Xo = 1; //initial condition
	Vo = 0; //initial condition
	k = 3;
	h = pi/(k*30); //Step increment for time (N=Totalt number of points)
	t =2* pi;

	x = Xo;
	v = Vo;

	
	for (double i = 0; i < t; i=i+h)
	{
		x1 = x + .5*(v + HeunsMetu1(v, k, x, h, i))*h;
		v1 = v + .5*(((-k)*k*x) + (-k)*k*HeunsMetu2(x, v, h, i))*h;
		errorfunction(x,x1,h);
		errorfunction(v,v1,h);
		x = x1;
		v = v1;

		//cout << "x=" << x1 << endl;
		//cout << "v=" << v1 << endl;
	}

	cout << "The approximate value of x=" << x << endl << "The actual value of x=" << Xo * cos(k*t) << endl << endl;
	cout << "The approximate value of v=" << v << endl << "The actual value of v=" << -k * x*sin(k*t) << endl;

	int j;
	cin >> j;

	return 0;
}