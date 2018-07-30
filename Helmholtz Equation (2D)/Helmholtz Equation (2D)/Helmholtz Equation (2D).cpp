// Helmholtz Equation (2D)
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

const int n = 50;
double a[n][n];  // matrix A
double b[n][n];  // result matrix (f(x)*delta^2) n x n
double x[n][n];     // matrix U (answer matrix)
double x_new[n][n]; // updated matrix U
double L = 2*3.14159;
double Lx = L;
double Ly = L;
double error = 1;
double EPSILON = pow(2, -2);
double lambda = .5;
int n_sqrt = sqrt(n);
double eigenvalue = 1;
double delta = (double)L / (n + 1); // delta x = delta y
double h = delta;
double diagonal = -(4 + eigenvalue * pow(delta, 2));

void print_matrix(double a[n][n], double b[n][n], int n)
{
	cout << "The entered matrix is:" << endl;
	for (int row = 0; row < n; row++)
	{
		cout << " ";
		for (int col = 0; col < n; col++)
		{
			cout << a[row][col] << " ";
		}
		cout << "| ";
		for (int col = 0; col < n; col++)
		{
			cout << b[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

double f(double x, double y) { return sin(x); } // f(j,k)}
double Fo(double x) { return sin(x + 0); } // u(x,y=0)
double FL(double x) { return sin(x + delta * (n_sqrt - 1)); } // u(x,y=Ly)
double Go(double y) { return sin(0 + y); } // u(x=0,y)
double GL(double y) { return sin(delta*(n_sqrt - 1) + y); } // u(x=Lx,y)

int main()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			x[i][j] = 1;
			x_new[i][j] = 0;
		}
	}	
	x[0][0] = 1;
	x[n - 1][n - 1] = 10;
	x_new[0][0] = x[0][0];
	x_new[n - 1][n - 1] = x[n - 1][n - 1];

	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			if (row == col)
			{
				a[row][col] = diagonal;
			}
			if ((row + 1) == col)
			{
				a[row][col] = 1;
			}
			if ((row - 1) == col)
			{
				a[row][col] = 1;
			}
		}
	}

	for (int row = 1; row < n - 1 ; row++)
	{
		for (int col = 1; col < n - 1 ; col++)
		{
			b[row][col] = f((row + 1)*delta, (col + 1)*delta)*pow(delta,2); // middle values
		}
	}
	for (int col = 0; col < n; col++)
	{
		b[0][col] = Go((1 + col)*delta); // top boundary
		b[n - 1][col] = GL((1 + col)*delta); // bottom boundary
	}
	for (int row = 0; row < n; row++)
	{
		b[row][0] = Fo((1 + row)*delta); // left boundary
		b[row][n - 1] = FL((1 + row)*delta); // right doundary
	}
	print_matrix(a, b, n);
	double b_new;
	int iterations = 0;
	while (iterations < n*100)
	{
		error = 0;
		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < n; k++)
			{
				x_new[i][k] = 0;
				for (int j = 0; j < n; j++)
				{
					if (i != j)
					{
						x_new[i][k] += a[i][j] * x[j][k]; // summing up the (n+1/2) terms
					}
				}
				b_new = b[i][k] - x[i][k + 1] - x[i][k - 1]; // using surrounding points to redefine b
				x_new[i][k] = ((b_new - x_new[i][k]) / a[i][i])*lambda + (1 - lambda)*(x[i][k]);
				error += abs(x_new[i][k] - x[i][k]);
				x[i][k] = x_new[i][k];
			}
		}
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				x_new[i][k] = 0;
				for (int j = 0; j < n; j++)
				{
					if (i != j)
					{
						x_new[i][k] += a[i][j] * x[j][k];
					}
				}
				b_new = b[i][k] - x[i + 1][k] - x[i - 1][k]; // using surrounding points to redefine b
				x_new[i][k] = ((b_new - x_new[i][k]) / a[i][i])*lambda + (1 - lambda)*(x[i][k]);
				error += abs(x_new[i][k] - x[i][k]);
				x[i][k] = x_new[i][k];
				//cout << "x " << x[i][k] << endl;
			}
		}
		//cout << error << endl;
		iterations++;
	}
	//print_matrix(a, b, n);
	ofstream x_value("x_value.txt");
	ofstream y_value("y_value.txt");
	ofstream z_value("z_value.txt");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "x" << i + 1 << j + 1 << "= " << x[i][j] << endl;
			x_value << i+1 << " ";
			y_value << j + 1 << " ";
			z_value << x[i][j] << " ";
		}
		x_value << endl;
		y_value << endl;
		z_value << endl;
	}
	x_value.close();
	y_value.close();
	z_value.close();
	system("PAUSE");
	return 0;
}
