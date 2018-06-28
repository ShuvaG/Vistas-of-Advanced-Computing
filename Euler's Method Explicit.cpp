// Euler's Method (EXPLICIT)
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	const double pi = 3.14159265358979323846;
	const double tmax = pi / 20;
	double h, t, u, error, u_ex;
	int alpha;

	alpha = 10;
	u_ex = sin(alpha*tmax);

	cout << "Enter t0: " << endl;
	cin >> t; //initial t value
	cout << "Enter u0: " << endl;
	cin >> u; //initial u(t) value
	cout << "Enter h value: " << endl;
	cin >> h; //t(n+1)-t(n); this is the change in the t value
	cout << endl << endl;

	for (t = 0; t <= tmax; t = t + h)  //this increases the t value to the next t value
		u = u + h * alpha* cos(t*alpha); //finds u(t) at a given t value

	error = abs((u_ex - u) / u_ex);

	cout << "The approximate value at t=" << t << " is " << u << endl << endl;
	cout << "The exact value at t=" << t << " is " << u_ex << endl << endl;
	cout << "The error is " << error << "%" << endl << endl;
	int j;
	cin >> j;
	return 0;
}