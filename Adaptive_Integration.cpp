//Adaptive Integration
#include <iostream>
#include <math.h>
using namespace std;
int alpha = 1;


int main()
{
	const double pi = 3.14159265358979323846;
	const double tmax = pi / 2;
	double h, t, u, error, u_ex, u1, tmin;
	double u2;
	double epsilon, delta, delta_desired, a = 0, phi;
	epsilon = pow(10, -6);
	u_ex = sin(alpha*tmax);

	tmin = 0;
	u = 0;
	h = .001;

	for (t = tmin; t <= tmax; t += h)  // This increases the t value to the next t value
	{
		u1 = u + h * alpha* cos(t*alpha); // This finds the value of u using one step.

		for (int tt = 0; tt < 2; tt++)
		{
			u2 = u + h * .5 * alpha* cos(tt*alpha); //This finds the value of u using two steps (
			u = u2;
		}
		delta = abs(u2 - u1); // We now compare the change in taking two steps vs. taking one step
		delta_desired = epsilon * (abs(u2) + h * alpha*cos(alpha*t)); // This established the change we want between u1 and u2.
		phi = delta_desired / delta;
		if (delta < delta_desired)
			a = .2;
		if (delta > delta_desired)
			a = .25;
		u = u1;
		h = h * pow(phi, a);
	}

	error = abs((u_ex - u2) / u_ex);

	cout << "The approximate value at t=" << tmax << " is " << u2 << endl << endl;
	cout << "The exact value at t=" << tmax << " is " << u_ex << endl << endl;
	cout << "The error is " << error << "%" << endl << endl;
	int j;
	cin >> j;
	return 0;
}