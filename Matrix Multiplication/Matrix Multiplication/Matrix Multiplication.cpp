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
double r;
int row1, col1, row2, col2;

void multiply_ijk()
{
		ofstream array_ijk("array_ijk");
		ofstream time_ijk("time_ijk");
		double cpu_time_used_ijk;
		clock_t start_ijk, end_ijk;
		row1 =0;
		col1 =0;
		row2 =0;
		col2 =0;
		for (int a = 0; a < 14; a++)
		{
			row1 += 50;
			col1 += 50;
			row2 += 50;
			col2 += 50;
			start_ijk = clock();
			for (int i = 0; i < row1; i++) // multiplies the two matricies
			{
				for (int j = 0; j < col2; j++)
				{
					sum = 0;
					for (int k = 0; k < col1; k++)
					{
						sum += matrix_1[i][k] * matrix_2[k][j];
					}
					mult_matrix[i][j] = sum;
				}
			}
			end_ijk = clock();
			cpu_time_used_ijk = ((double)(end_ijk - start_ijk)) / CLOCKS_PER_SEC;
			array_ijk << row1 << " ";
			time_ijk << cpu_time_used_ijk << " ";
		}
		array_ijk.close();
		time_ijk.close();
}
void multiply_kij()
{
	ofstream array_kij("array_kij");
	ofstream time_kij("time_kij");
	double cpu_time_used_kij;
	clock_t start_kij, end_kij;
	row1 = 0;
	col1 = 0;
	row2 = 0;
	col2 = 0;
	for (int a = 0; a < 14; a++)
	{
		row1 += 50;
		col1 += 50;
		row2 += 50;
		col2 += 50;
		start_kij = clock();
		for (int k = 0; k < col1; k++) // multiplies the two matricies
		{
			for (int i = 0; i < row1; i++)
			{
				r = matrix_1[i][k];
				for (int j = 0; j < col2; j++)
				{
					mult_matrix[i][j] += r * matrix_2[k][j];
				}
			}
		}
		end_kij = clock();
		cpu_time_used_kij = ((double)(end_kij - start_kij)) / CLOCKS_PER_SEC;
		array_kij << row1 << " ";
		time_kij << cpu_time_used_kij << " ";
	}
	array_kij.close();
	time_kij.close();
}
void multiply_jki()
{

	ofstream array_jki("array_jki");
	ofstream time_jki("time_jki");
	double cpu_time_used_jki;
	clock_t start_jki, end_jki;
	row1 = 0;
	col1 = 0;
	row2 = 0;
	col2 = 0;
	start_jki = clock();
	for (int a = 0; a < 14; a++)
	{
		row1 += 50;
		col1 += 50;
		row2 += 50;
		col2 += 50;
		for (int j = 0; j < col2; j++) // multiplies the two matricies
		{
			for (int k = 0; k < col1; k++)
			{
				r = matrix_2[k][j];
				for (int i = 0; i < row1; i++)
				{
					mult_matrix[i][j] += matrix_1[i][k] * r;
				}
			}
		}
		end_jki = clock();
		cpu_time_used_jki = ((double)(end_jki - start_jki)) / CLOCKS_PER_SEC;
		array_jki << row1 << " ";
		time_jki << cpu_time_used_jki << " ";
	}
	array_jki.close();
	time_jki.close();
}
int main()
{
	const int n = 700;
	
	for (int row = 0; row < n; row++) // populates first matrix
	{
		for (int col = 0; col < n; col++)
		{

			matrix_1[row][col] = 1;
			matrix_2[row][col] = 2;
			mult_matrix[row][col] = 0;

		}
	}
	multiply_ijk();
	multiply_jki();
	multiply_kij();

	//cout << "The result of multiplying matrix 1 with matrix 2 is: " << endl;
	//for (int row = 0; row < row1; row++)
	//{
	//	for (int col = 0; col < col2; col++)
	//	{
	//		cout << mult_matrix[row][col] << " ";
	//	}
	//	cout << endl;
	//}
	
	system("PAUSE");
	return 0;
}
