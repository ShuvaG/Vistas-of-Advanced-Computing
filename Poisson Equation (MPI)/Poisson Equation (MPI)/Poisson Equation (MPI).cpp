// Helmholtz Equation (1D)
#include <iostream>
#include <math.h>
#include <fstream>
#include <ctime>
#include "mpi.h"
using namespace std;

int const N = 100;
double a[N][N];
double b[N];
double x[N];
double x_new[N];
double x_new1[N];

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
	double diagonal = -2;

	// Setting up the MPI Environment
	int rank, size, total;
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	// Initializating Values
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

	// Calculating each u value
	const clock_t begin_time = clock();
	while (error / n > EPSILON)
	{
		error = 0;
		for (int i = rank; i < n; i+=size)
		{
			x_new[i] = 0;
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					x_new[i] += a[i][j] * x[j];
				}
			}
			x_new[i] = ((b[i] - x_new[i]) / a[i][i]);

			MPI_Allgather(x_new, 1, MPI_DOUBLE, x_new1, 1, MPI_DOUBLE, MPI_COMM_WORLD); // Gathering the whole array

			error += abs(x_new[i] - x[i]);
		}
		for (int i = 0; i < n; i++)
		{
			x[i] = x_new[i];
		}
	}
	const clock_t end_time = clock();
	int total_time, tot;
	total_time = end_time - begin_time;
	MPI_Reduce(&total_time, &tot, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

	// Calculating Error
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

	// Printing results
	for (int i = 0; i < n; i++)
	{
		printf("x %d = %f \n", i + 1, x[i]);
	}
	printf("The error is: %f \n", tot[n - 1] / tot2[n - 1]);
	printf("It took %d seconds.\n", total_time);
	MPI_Finalize();
	return 0;
}
////////////////////////////////////////////////////////////////////////////////