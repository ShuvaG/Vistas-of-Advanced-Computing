// Matrix Multiplication
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	cout << "Computation for a 2048 x 2048 will take over a minute. Please wait." << endl;
	int *matrix_1, *matrix_2, *mult_matrix;
	int n = 2048;
	int B = 128;
	matrix_1 = (int*)malloc(n*n * sizeof(int));
	matrix_2 = (int*)malloc(n*n * sizeof(int));
	mult_matrix = (int*)malloc(n*n * sizeof(int));

	if (matrix_1 == NULL)
	{
		printf("Error memory not allocated for mark");
		exit(0);
	}

	clock_t start, end;
	double cpu_time_used;
	int row1 = n, col1 = n, row2 = n, col2 = n;

	for (int row = 0; row < n*n; row++) // populates first matrix
	{
			matrix_1[row]= 1;
			matrix_2[row] = 2;
			mult_matrix[row] = 0;
	}
	int sum = 0;
	start = clock();
//#pragma loop(no_vector)
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
							mult_matrix[i+j*n]+= matrix_1[i + k * n]*matrix_2[k + j * n];
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
	//		cout << mult_matrix[row + col * n] << " ";
	//	}
	//	cout << endl;
	//}

	system("PAUSE");
	return 0;
}