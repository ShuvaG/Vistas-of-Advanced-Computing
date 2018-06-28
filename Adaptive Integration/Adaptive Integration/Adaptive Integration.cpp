// Euler's Method with Adaptive Integration
#include <iostream>
#include <math.h>
using namespace std;
int alpha = 1;

double adaptive_int(double u1, double u, double h, double t)
{
	double u2;
	double epsilon, delta, delta_desired, a = 0, phi;
	epsilon = pow(10, -6);
	for (int t = 0; t < 2; t++) // This finds the value of u using two steps
	{
		u2 = u + h * .5 * alpha* cos(t*alpha);
		u = u2;
	}

	delta = abs(u2 - u1); // We now compare the change in taking two steps vs. taking one step
	delta_desired = epsilon * (abs(u) + h * alpha*cos(alpha*t));
	phi = delta_desired / delta;

	if (delta < delta_desired)
	{
		a = .2;
	}
	if (delta > delta_desired)
	{
		a = .25;
	}
	h = h * pow(phi, a);
	return h;
}

int main()
{
	const double pi = 3.14159265358979323846;
	const double tmax = pi / 2;
	double h, t, u, error, u_ex, u1;
	u_ex = sin(alpha*tmax);

	t = 0;
	u = 0;
	h = .01;

	for (t = 0; t <= tmax; t += h)  //this increases the t value to the next t value
	{
		u1 = u + h * alpha* cos(t*alpha); //finds u(t) at a given t value
		h = adaptive_int(u1, u, h, t);
		u = u1;
	}

	error = abs((u_ex - u) / u_ex);

	cout << "The approximate value at t=" << t << " is " << u << endl << endl;
	cout << "The exact value at t=" << t << " is " << u_ex << endl << endl;
	cout << "The error is " << error << "%" << endl << endl;
	int j;
	cin >> j;
	return 0;
}