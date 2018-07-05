// Matrix Multiplication
#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

int const N = 700;
double matrix_1[N][N];
double matrix_2[N][N];
double mult_matrix[N][N];
double sum = 0;

int main()
{
	const int n = 700;
	int row1 = 0, col1 = 0, row2 = 0, col2 = 0;
	//int response;
	ofstream array("array_jki");
	ofstream time("time_jki");
	clock_t start, end;
	double cpu_time_used;

	//cout << "Enter the dimensions of the first matrix: ";
	//cin >> row1 >> col1;
	//cout << "Enter the dimensions of the second matrix: ";
	//cin >> row2 >> col2;

	//cout << endl << "~Entering value for matrix 1~" << endl;
	for (int row = 0; row < n; row++) // populates first matrix
	{
		for (int col = 0; col < n; col++)
		{
			//cout << "Enter the value for a" << row + 1 << col + 1 << ": ";
			//cin >> response;
			matrix_1[row][col] = 1;
		}
	}
	//cout << endl << "~Entering value for matrix 2~" << endl;
	for (int row = 0; row < n; row++) // poopulates second matrix
	{
		for (int col = 0; col < n; col++)
		{
			//cout << "Enter the value for b" << row + 1 << col + 1 << ": ";
			//cin >> response;
			matrix_2[row][col] = 2;
		}
	}
	for (int row = 0; row < n; row++) // initilizes every postion with a zero
	{
		for (int col = 0; col < n; col++)
		{
			mult_matrix[row][col] = 0;
		}
	}
	double r;
	for (int a = 0; a < 14; a++)
	{
		row1 += 50;
		col1 += 50;
		row2 += 50;
		col2 += 50;
		start = clock();
		for (int j = 0; j < col2; j++) // multiplies the two matricies
		{
			for (int k = 0; k < col1; k++)
			{
				r = matrix_2[k][j];
				for (int i = 0; i < row1; i++)
				{
					mult_matrix[i][j] += r * matrix_1[i][k];
				}
			}
		}
		end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
		array << row1 << " ";
		time << cpu_time_used << " ";
	}
	
	//cout << "The result of multiplying matrix 1 with matrix 2 is: " << endl;
	//for (int row = 0; row < row1; row++)
	//{
	//	for (int col = 0; col < col2; col++)
	//	{
	//		cout << mult_matrix[row][col] << " ";
	//	}
	//	cout << endl;
	//}
	array.close();
	time.close();

	system("PAUSE");
	return 0;
}