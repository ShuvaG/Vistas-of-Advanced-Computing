// Successive Over Relaxtion (Modification of Gauss-Seidel)
#include <iostream>
#include <math.h>
using namespace std;

int const N = 100;
double a[N][N];
double b[N];
double x[N];
double x_new[N];

double roundoff(double number, int x, int type)
{
	double newNumber, bigger_number, finalAnswer, roundofferror, multiplier;
	string up, down, integer;
	finalAnswer = 0;
	multiplier = pow(10, x); // how many decimal places do you want?
	newNumber = number * multiplier; // this makes the number bigger (moves decimal place) and chops off the numbers after the decimal.
	switch (type) // this decides if you want to round up, down, or to the closest integer
	{
	case 1: // rounds up
		bigger_number = ceilf(newNumber);
		finalAnswer = bigger_number / multiplier;
		break;
	case 2: // rounds down
		bigger_number = floorf(newNumber);
		finalAnswer = bigger_number / multiplier;
		break;
	case 3: // rounds to nearest integer
		bigger_number = round(newNumber);
		finalAnswer = bigger_number / multiplier;
		break;
	}
	//cout << "The rounded number is: " << finalAnswer << endl;
	//roundofferror = abs((number - finalAnswer) / number);
	//cout << "The round-off error: " << roundofferror << endl;
	return finalAnswer;
}
int input_matrix()
{
	double user_input;
	int n;
	cout << "Enter the dimention of your square matrix: ";
	cin >> n;
	cout << "Enter the values you want in your matrix:" << endl;
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++) // this populates a[][]
		{
			cout << "Enter the value for a" << row + 1 << col + 1 << "= ";
			cin >> user_input;
			a[row][col] = user_input;
		}
	}
	cout << endl;
	int counter = 1;
	for (int j = 0; j < n; j++) // this populates b[][]
	{
		cout << "Enter the value for b" << counter << n + 1 << "= ";
		cin >> user_input;
		b[j] = user_input;
		counter++;
	}
	return n; 
}
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

int main()
{
	//int n;
	//double error=1;
	//const double EPSILON = pow(10, -6);
	//x[0] = 1;
	//n = input_matrix();
	//print_matrix(a, b, n);

	const int n = 3;
	double a[n][n] = {
		{ 3,-.1,-.2 },
		{ .1,7,-.3 },
		{ .3,-.2,10 } };
	double b[n] = { 7.85,-19.3,71.4 };
	double error = 1;
	double EPSILON = pow(10, -6);
	double lambda = 1.4; // 1 > lambda > 2
	x[0] = 300; // initial guess
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
	for (int i = 0; i < n; i++)
	{
		cout << "x" << i + 1 << "= " << roundoff(x[i], 2, 3) << endl;
	}
	system("PAUSE");
	return 0;
}
