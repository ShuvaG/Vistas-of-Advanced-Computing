// Matrix Multiplication
#include <iostream>
#include <time.h>
using namespace std;

int const N = 512;
double matrix_1[N][N];
double matrix_2[N][N];
double mult_matrix[N][N];

int main()
{
	clock_t start, end;
	double cpu_time_used;
	const int n = 512;
	int row1 = n, col1 = n, row2 = n, col2 = n;

	//cout << "Enter the dimensions of the first matrix: ";
	//cin >> row1 >> col1;
	//cout << "Enter the dimensions of the second matrix: ";
	//cin >> row2 >> col2;

	//cout << endl << "~Entering value for matrix 1~" << endl;
	for (int row = 0; row < row1; row++) // populates first matrix
	{
		for (int col = 0; col < col1; col++)
		{
			matrix_1[row][col] = 1;
		}
	}
	//cout << endl << "~Entering value for matrix 2~" << endl;
	for (int row = 0; row < row2; row++) // poopulates second matrix
	{
		for (int col = 0; col < col1; col++)
		{
			matrix_2[row][col] = 1;
		}
	}
	for (int row = 0; row < row1; row++) // initilizes every postion with a zero
	{
		for (int col = 0; col < col2; col++)
		{
			mult_matrix[row][col] = 0;
		}
	}

	int B = 256;
	start = clock();
	for (int ii = 0; ii < n; ii+=B)
	{
		for (int jj = 0; jj < n; jj+=B)
		{
			for (int kk = 0; kk < n; kk += B)
			{
				for (int i = ii; i < ii + B; i++) // inside the blocks
				{
					for (int j = jj; j < jj + B; j++)
					{
						for (int k = kk; k < kk+B; k++)
						{
							mult_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
						}
					}
				}
			}
		}
	}
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "cpu_time_used: " << cpu_time_used << " seconds." << endl;

	//cout << "The result of multiplying matrix 1 with matrix 2 is: " << endl;
	//for (int row = 0; row < n; row++)
	//{
	//	for (int col = 0; col < n; col++)
	//	{
	//		cout << mult_matrix[row][col] << " ";
	//	}
	//	cout << endl;
	//}

	system("PAUSE");
	return 0;
}