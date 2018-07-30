// 1D Wave Equation (Explicit)

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

const int n = 100;
double c = 1;
double pi = 3.1415926;
double L = 2 * pi;
double delta_t = .01;
double delta_x = L / (double)(n);
double t_max = 20;

double u_old[n];
double u_current[n];
double u_new[n];

double U(double x, double t) { return 1 / 2 * cos(x + t) + 1 / 2 * cos(x - t); }
double g(double x) { return sin(x); } // initial condition g

int main()
{
	ofstream u_values("u_values.txt");
	int j = 0;
	for (double x = 0; x < L; x += delta_x)
	{
		u_current[j] = U(x, 0);
		u_old[j] = u_current[j] - 2 * delta_t*g(x);
		j++;
	}
	double t = 0;
	while (t < t_max)
	{
		for (int j = 1; j < n - 1; j++)
		{
			u_new[j] = 2 * u_current[j] - u_old[j] + pow(c, 2) * pow(delta_t, 2) / pow(delta_x, 2) *(u_current[j - 1] - 2 * u_current[j] + u_current[j + 1]);
		}
		for (int j = 1; j < n - 1; j++)
		{
			u_new[j] = 2 * u_current[j] - u_old[j] + pow(c, 2) * pow(delta_t, 2) / 2 * ((u_new[j - 1] - 2 * u_new[j] + u_new[j + 1]) / pow(delta_x, 2) + (u_old[j - 1] - 2 * u_old[j] + u_old[j + 1]) / pow(delta_x, 2));
		}
		for (int j = 0; j < n; j++)
		{
			u_old[j] = u_current[j]; // making current values old
			u_current[j] = u_new[j]; // making new values current
			u_values << u_current[j] << " ";
		}
		u_values << endl;
		t += delta_t;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "u(" << i + 1 << ") = " << u_current[i] << endl;
	}
	u_values.close();
	system("PAUSE");
	return 0;
}