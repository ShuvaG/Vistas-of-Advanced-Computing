// 1D Diffusion (Explicit)

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

const int n = 20; //
double u[n];
double u_new[n];
double L = 2;
double t_max = 2;
double delta_x = L / n;
double N = 2;
double k = 1; // diffusion constant
double rho = 1; // density
double pi = 3.14159;
double cp = 1;
double D = k / (rho*cp);
int iterations = L / delta_x;
double Ao = 1;
double delta_t = pow(delta_x, 2) / (2 * D);

double A(double t) { return Ao * exp((1 - pow((pi*N / L), 2)*k)*pow(pi*N / L, 2)*D*t); }
double U(double x, double t) { return A(t)*sin(pi*N*x / L); }

int main()
{

	u[0] = 0;
	u_new[0] = 0;
	u[n - 1] = 30;
	u_new[n - 1] = 30;
	int j = 0;
	for (double x = 0; x < L; x += delta_x)
	{
		u[j] = U(x, 0);
		j++;
	}
	double t = 0;
	double EPSILON = pow(10, -6);
	double error;
	while (t < t_max)
	{
		error = 0;
		for (int j = 1; j < iterations - 1; j++)
		{
			u_new[j] = u[j] + D * delta_t / pow(delta_x, 2) *(u[j - 1] - 2 * u[j] + u[j + 1]);
		}
		for (int j = 1; j < iterations; j++)
		{
			error += abs(u_new[j] - u[j]);
			u[j] = u_new[j]; // replacing the values
		}
		//cout << "error: " << error << endl;
		t += delta_t;
	}
	ofstream u_values("u_values.txt");
	for (int i = 0; i < n; i++)
	{
		cout << "u(" << i + 1 << ") = " << u[i] << endl;
		u_values << u[i] << " ";
	}
	u_values.close();
	system("PAUSE");
	return 0;
}