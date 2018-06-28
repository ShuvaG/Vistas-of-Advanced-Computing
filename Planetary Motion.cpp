// Planetary Motion
#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
	const int n = 365 * 32;
	double x[n], y[n], vx[n], vy[n], xstar, ystar, vxstar, vystar;
	//double const tmax = 3.154*pow(10, 7);
	const double G = 6.754 * pow(10, -11);
	const double Ms = 1.989 * pow(10, 30);
	double const h = 86400 / 32; //  0.05 of a day
	x[0] = 1.52*pow(10, 11);
	y[0] = 0;
	vx[0] = 0;
	vy[0] = 2.93*pow(10, 4);
	ofstream outputx("output_x");
	ofstream outputy("output_y");

	for (int t = 0; t < n; t++)
	{
		xstar = x[t] + h * vx[t];
		ystar = y[t] + h * vy[t];
		vxstar = vx[t] - (G*Ms*h*x[t]) / pow((x[t] * x[t] + y[t] * y[t]), 1.5);
		vystar = vy[t] - (G*Ms*h*y[t]) / pow((x[t] * x[t] + y[t] * y[t]), 1.5);
		x[t + 1] = x[t] + .5*h*(vx[t] + vxstar);
		y[t + 1] = y[t] + .5*h *(vy[t] + vystar);
		vx[t + 1] = vx[t] - .5*G*Ms*h*(x[t] / pow((x[t] * x[t] + y[t] * y[t]), 1.5) + xstar / pow((x[t] * x[t] + y[t] * y[t]), 1.5));
		vy[t + 1] = vy[t] - .5*G*Ms*h*(y[t] / pow((x[t] * x[t] + y[t] * y[t]), 1.5) + ystar / pow((x[t] * x[t] + y[t] * y[t]), 1.5));
		outputx << x[t] << ' ';
		outputy << y[t] << ' ';
	}
	outputx.close();
	outputy.close();
	cout << "x=" << x[n - 1] << endl;
	cout << "vx=" << vx[n - 1] << endl;
	cout << "y=" << y[n - 1] << endl;
	cout << "vy=" << vy[n - 1] << endl;

	system("PAUSE");

	return 0;
}