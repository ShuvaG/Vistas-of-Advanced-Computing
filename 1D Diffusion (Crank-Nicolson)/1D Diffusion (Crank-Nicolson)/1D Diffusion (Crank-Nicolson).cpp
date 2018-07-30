// Crank Nicolson 

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

const int n = 20;
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
double U(double x, double t) { return A(t)*sin(3.14159*N*x / L); }

int main()
{
	u[0] = 0;
	u[n - 1] = 20;
	u_new[0] = u[0];
	u_new[n - 1] = u[n - 1];
	int j = 0;
	for (double x = 0; x < L; x += delta_x)
	{
		u[j] = U(x, 0); // initial time boundary
		j++;
	}

	double t = 0;
	double error = 0;
	while (t < t_max)
	{
		error = 0;
		for (int j = 1; j < iterations - 1; j++)
		{
			u_new[j] = u[j] + D * delta_t / pow(delta_x, 2) *(u[j - 1] - 2 * u[j] + u[j + 1]); // explicit
		}
		for (int j = 1; j < iterations - 1; j++)
		{
			u_new[j] = u[j] + D * delta_t / 2 * ((u[j - 1] - 2 * u[j] + u[j + 1]) / pow(delta_x, 2) + (u_new[j - 1] - 2 * u_new[j] + u_new[j + 1]) / pow(delta_x, 2));
		}
		for (int j = 1; j < iterations; j++)
		{
			error += abs(u_new[j] - u[j]);
			u[j] = u_new[j];
		}
		t += delta_t;
		//cout << "error: " << error << endl;
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