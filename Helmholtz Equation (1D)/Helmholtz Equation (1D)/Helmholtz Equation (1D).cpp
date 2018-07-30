// Helmholtz Equation (1D)
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

int const N = 100;
double a[N][N];
double b[N];
double x[N];
double x_new[N];

void print_matrix(double a[N][N], double b[N], int n)
{
	cout << "The entered matrix is:" << endl;
	for (int row = 0; row < n; row++)
	{
		cout << " ";
		for (int col = 0; col < n; col++)
			cout << a[row][col] << " ";
		cout << "| " << b[row] << endl;
	}
	cout << endl;
}

double f(double x) { return sin(x); }

int main()
{
	const int n = 65; // matrix dimension
	double eigenvalue = 1;
	double a_answer = 1;
	double b_answer = 1;
	int L = 3.14159;

	double error = 1;
	double EPSILON = pow(10, -6);
	double lambda = 1.4; // 1 < lambda < 2

	double h = (double)L / (n + 1);
	double diagonal = -(2 + eigenvalue * h * h);

	x[0] = a_answer;
	x[n - 1] = b_answer;
	b[0] = pow(h, 2)*f((1 * h)) - a_answer;
	b[n - 1] = pow(h, 2)*f(((n - 1) * h)) - b_answer;

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
	for (int row = 1; row < n - 1; row++)
	{
		b[row] = pow(h, 2)*f((1 + row)*h);
	}
	//print_matrix(a, b, n);
	while (error / n > EPSILON)
	{
		error = 0;
		for (int i = 0; i < n; i++)
		{
			x_new[i] = 0;
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					x_new[i] += a[i][j] * x[j];
				}
			}
			x_new[i] = ((b[i] - x_new[i]) / a[i][i])*lambda + (1 - lambda)*(x[i]);
			error += abs(x_new[i] - x[i]);
			x[i] = x_new[i];
		}
	}
	double error2;
	double numerator;
	double denomenator;
	double tot[n];
	double tot2[n];

	for (int row = 0; row < n; row++)
	{
		numerator = 0;
		denomenator = 0;
		for (int col = 0; col < n; col++)
		{
			numerator += a[row][col] * x[col];
			denomenator += abs(a[row][col])*abs(x[col]);
		}
		tot[row] = abs(numerator - b[row]);
		tot2[row] = denomenator + abs(b[row]);
	}
	//print_matrix(a, b, n);
	ofstream u_values("u_values.txt");
	for (int i = 0; i < n; i++)
	{
		cout << "x" << i + 1 << "= " << x[i] << endl;
		u_values << x[i] << " ";

	}
	cout << endl << "The error is: " << tot[n - 1] / tot2[n - 1] << endl << endl;
	u_values.close();
	system("PAUSE");
	return 0;
}
////////////////////////////////////////////////////////////////////////////////