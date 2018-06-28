// Gaussian Elimination
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int const N = 2;
double a[N][N];
double b[N];
double x[N];

// declaring functions:
//int input_matrix();
void print_matrix(double a[N][N], double b[N], int n);
void pivot(double a[N][N], int k, double b[N], int n);
void solve_matrix(double a[N][N], double b[N], int n);
double roundoff(double number, int x, int type);


/*int input_matrix()
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
		cout << "Enter the value for b:" << counter << n + 1 << "= ";
		cin >> user_input;
		b[j] = user_input;
		counter++;
	}
	return n;
}*/
double roundoff(double number, int x, int type)
{
	double newNumber, bigger_number, finalAnswer, roundofferror, multiplier;
	string up, down, integer;
	finalAnswer = 0;
	multiplier = pow(10, x); // how many decimal places do you want?
	newNumber = number * multiplier;
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
void pivot(double a[N][N], int k, double b[N], int n)
{
	double largest_num;
	double copy_row[N];
	double copy_b;
	int new_row = k;
	largest_num = abs(a[k][k]); // this predefines the current row/column as the largest value (this is along the main diagonal)
	for (int i = k + 1;i < n;i++) // this will go down the column and find a larger value
	{
		if (abs(a[i][k]) > largest_num) // if the value is larger than the previous one, it replaces that value
		{
			largest_num = abs(a[i][k]);
			new_row = i; // this will store the new row number as the largest value
		}
	}
	if (new_row != k) // this condition is satisifed if a new row is defined to have the largest value
	{
		for (int i = 0; i < n; i++) // this loop will make a copy of the "a" values in the old max row
		{
			copy_row[i] = a[k][i];
		}
		copy_b = b[k]; // this will make of copy of the "b" value in the old max row
		for (int j = k;j < n;j++) // this loop will swap the two rows
		{
			a[k][j] = a[new_row][j]; // this copies the new row into the location previous max row
			a[new_row][j] = copy_row[j]; // this copies the old row into the location of where the new row used to be
		}
		b[k] = b[new_row]; // this copies the new b value into the location of the previous max row
		b[new_row] = copy_b; // this copies the old b value into the location of where the new row used to be
	}
	print_matrix(a, b, n);
}
void solve_matrix(double a[N][N], double b[N], int n)
{
	double factor;
	double sum;

	for (int k = 0; k < n - 1; k++) // column index
	{
		pivot(a, k, b, n);
		for (int i = k + 1; i < n; i++) // row index
		{
			factor = a[i][k] / a[k][k]; // decides the factor to multiply in order to get a zero
			factor = roundoff(factor, 3, 3);
			for (int j = k + 1; j < n; j++) // this loops makes it zero
			{
				a[i][j] = a[i][j] - factor * a[k][j];
			}
			b[i] = b[i] - factor * b[k]; 
		}
	}
	x[n - 1] = b[n - 1] / a[n - 1][n - 1]; // this solves for the value on the last row (if a[n-1][n-1] = 0, cannot be solved)
	for (int i = n - 1; i >= 0; i--) // this loops starts the backwards subsititution
	{
		sum = b[i];
		for (int j = i + 1; j < n; j++)
		{
			sum = sum - a[i][j] * x[j];
		}
		x[i] = sum / a[i][i];
	}

	cout << "The solution is:" << endl;
	for (int i = 0; i < n; i++) // this will display the solutions to the matrix
	{
		cout << "x" << i+1 << "=" << x[i] << endl;
	}
}
int main()
{
	const int n = 2;
	double x[n];
	double a[n][n] = {
		{.0003*pow(10,20), 3*pow(10,20)},
		{pow(10,20), pow(10,20)} };
	double b[n] = { 2.0001*pow(10,20), pow(10,20) };

	//int n;
	//n = input_matrix(); // this asks users to put in their own matrix
	print_matrix(a, b, n); // this will print the inputed matrix
	solve_matrix(a, b, n); // this solves the matrix using Gaussian Elimination and Partial Pivoting

	system("PAUSE");
	return 0;
}