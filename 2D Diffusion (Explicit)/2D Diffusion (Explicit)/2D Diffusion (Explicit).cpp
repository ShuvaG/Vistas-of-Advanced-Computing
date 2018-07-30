// 2D Diffusnion (Explicit)

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

const int n = 70; //
double u[n][n];
double u_new[n][n];
double L = 1;
double t_max = 2;
double delta = L / (n+1); // delta_x=delta_y
double delta_x = delta;
double delta_y = delta;
double N = 2;
double k = 1; // diffusion constant
double rho = 1; // density
double pi = 3.14159;
double cp = 1;
double D = k / (rho*cp);
int iterations = L / delta_x;
double Ao = 1;
double delta_t = (double)pow(delta_x, 2) / (2 * D);

double A(double t) { return Ao * exp((1 - pow((pi*N / L), 2)*k)*pow(pi*N / L, 2)*D*t); }
double U(double x, double t) { return A(t)*sin(pi*N*x / L); }

int main()
{
	double top = 2.5;
	double bottom = 2.5;
	double left = 2.5;
	double right = 2.5;
	for (int j = 0; j < n; j++)
	{
		for (int j = 0; j < n; j++)
		{
			delta_t = pow(delta_x, 2) / (2 * D);
			for (int k = 0; k < n; k++)
			{
				if (j == 0) // top boundary
				{
					u[j][k] = top;
					u_new[j][k] = u[j][k];
				}
				if (j == n - 1) // bottom boundary
				{
					u[j][k] = bottom;
					u_new[j][k] = u[j][k];
				}
				if (k == 0) // left boundary
				{
					u[j][k] = left;
					u_new[j][k] = u[j][k];
				}
				if (k == n - 1) // right boundary
				{
					u[j][k] = right;
					u_new[j][k] = u[j][k];
				}
			}
		}
	}
	for (int row = 1;row < n - 1; row++)
	{
		for (int col = 1;col < n - 1;col++)
		{
			u[row][col] = U((double)row*delta, 0); // center 
			u_new[row][col] = 0;
		}
	}
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
			cout << u[row][col] << " ";
		cout << endl;
	}
	double t = 0;
	double EPSILON = pow(10, -6);
	double error;
	double delta_t = (double)pow(delta_x, 2) / (2 * D);


	while (t < t_max)
	{
		error = 0;
		for (int j = 1; j < n - 1; j++) // for the x values 
		{
			for (int k = 1; k < n - 1; k++)
			{
				u_new[j][k] = u[j][k] + D * delta_t / pow(delta_x, 2)* (u[j][k - 1] - 2 * u[j][k] + u[j][k + 1]); // ujk for n+1/2 
			}
		}
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				error += abs(u_new[j][k] - u[j][k]);
				u[j][k] = u_new[j][k]; // replacing the values
			}
		}
		for (int k = 1; k < n - 1; k++) // for the y values 
		{
			for (int j = 1; j < n; j++)
			{
				u_new[j][k] = u[j][k] + D * delta_t / pow(delta_x, 2)* (u[j - 1][k] - 2 * u[j][k] + u[j + 1][k]);
			}
		}

		for (int k = 0; k < n; k++)
		{
			for (int j = 0; j < n; j++)
			{
				error += abs(u_new[j][k] - u[j][k]);
				u[j][k] = u_new[j][k]; // replacing the values
			}
		}
		t += delta_t;
	}
	for (int j = 0; j < n; j++)
	{
		delta_t = pow(delta_x, 2) / (2 * D);
		for (int j = 0; j < n; j++)
		{
			delta_t = pow(delta_x, 2) / (2 * D);
			for (int k = 0; k < n; k++)
			{
				if (j == 0) // top boundary
				{
					u[j][k] = top;
					u_new[j][k] = u[j][k];
				}
				if (j == n - 1) // bottom boundary
				{
					u[j][k] = bottom;
					u_new[j][k] = u[j][k];
				}
				if (k == 0) // left boundary
				{
					u[j][k] = left;
					u_new[j][k] = u[j][k];
				}
				if (k == n - 1) // right boundary
				{
					u[j][k] = right;
					u_new[j][k] = u[j][k];
				}
			}
		}
	}
	ofstream u_values("u_values.txt");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "u" << i + 1 << j + 1 << " = " << u[i][j] << endl;
			u_values << u[i][j] << " ";
		}
		u_values << endl;
	}
	u_values.close();
	system("PAUSE");
	return 0;
}