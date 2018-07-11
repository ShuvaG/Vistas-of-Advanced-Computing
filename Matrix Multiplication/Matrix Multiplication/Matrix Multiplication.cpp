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

void multiply_ijk(int row1, int col1, int row2, int col2)
{
	ofstream array_ijk("array_ijk");
	ofstream time_ijk("time_ijk");
	double cpu_time_used_ijk;
	clock_t start_ijk, end_ijk;
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
	cout << "Time it took for ijk: " << cpu_time_used_ijk << " seconds." << endl;
	//array_ijk << row1 << " ";
	//time_ijk << cpu_time_used_ijk << " ";
	array_ijk.close();
	time_ijk.close();
}
void multiply_kij(int row1, int col1, int row2, int col2)
{
	ofstream array_kij("array_kij");
	ofstream time_kij("time_kij");
	double cpu_time_used_kij;
	clock_t start_kij, end_kij;
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
	cout << "Time it took for kij: " << cpu_time_used_kij << " seconds." << endl;
	//array_kij << row1 << " ";
	//time_kij << cpu_time_used_kij << " ";
	array_kij.close();
	time_kij.close();
}
void multiply_jki(int row1, int col1, int row2, int col2)
{
	ofstream array_jki("array_jki");
	ofstream time_jki("time_jki");
	double cpu_time_used_jki;
	clock_t start_jki, end_jki;
	start_jki = clock();
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
	cout << "Time it took for jki: " << cpu_time_used_jki << " seconds." << endl;
	//array_jki << row1 << " ";
	//time_jki << cpu_time_used_jki << " ";
	array_jki.close();
	time_jki.close();

}
void transposed_method(int row1, int col1, int row2, int col2)
{
	ofstream array_transposed("array_transposed");
	ofstream time_transposed("time_transposed");
	double cpu_time_used_transposed;
	clock_t start_transposed, end_transposed;
	start_transposed = clock();
	for (int row = 0; row < col2; row++) // transposed the matrix
	{
		for (int col = 0; col < row2; col++)
		{
			matrix_2[row][col] = matrix_2[col][row];
		}
	}
	for (int i = 0; i < row1; i++) // multiplies the two matricies
	{
		for (int j = 0; j < col2; j++)
		{
			sum = 0;
			for (int k = 0; k < col1; k++)
			{
				sum += matrix_1[i][k] * matrix_2[j][k];
			}
			mult_matrix[i][j] = sum;
		}
	}
	end_transposed = clock();
	cpu_time_used_transposed = ((double)(end_transposed - start_transposed)) / CLOCKS_PER_SEC;
	cout << "Time it took for tranposed method: " << cpu_time_used_transposed << " seconds." << endl;
	//array_transposed << row1 << " ";
	//time_transposed << cpu_time_used_transposed << " ";
	array_transposed.close();
	time_transposed.close();

}
void populating_matrix_1(int row1, int col1)
{
	double response;

	for (int row = 0; row < row1; row++) // populates first matrix
	{
		for (int col = 0; col < col1; col++)
		{
			//cout << "Enter value for a" << row + 1 << col + 1 << ": ";
			//cin >> response;
			//matrix_1[row][col] = response;
			matrix_1[row][col] = 1;
		}
	}
	cout << endl;
}
void populating_matrix_2(int row2, int col2)
{
	double response;
	for (int row = 0; row < row2; row++) // populates second matrix
	{
		for (int col = 0; col < col2; col++)
		{
			//cout << "Enter value for b" << row + 1 << col + 1 << ": ";
			//cin >> response;
			//matrix_2[row][col] = response;
			matrix_2[row][col] = 2;
		}
	}
}
void populating_mult_matrix(int row1, int row2)
{
	for (int row = 0; row < row1; row++) // populates multiplied matrix
	{
		for (int col = 0; col < col2; col++)
		{
			mult_matrix[row][col] = 0;
		}
	}
}
void printing_answer(int row1, int col2)
{
	cout << "The result of multiplying matrix 1 with matrix 2 is: " << endl;
	for (int row = 0; row < row1; row++)
	{
		for (int col = 0; col < col2; col++)
		{
			cout << mult_matrix[row][col] << " ";
		}
		cout << endl;
	}
}
int main()
{

	// cout << "Enter dimensions for matrix 1: ";
	// cin >> row1 >> col1;
	// cout << "Enter dimensions for matrix 2: ";
	// cin >> row2 >> col2;

	int n = 700;
	row1 = n;
	col1 = n;
	row2 = n;
	col2 = n;
	cout << "The program is currently preset as a 700 x 700 with the matricies set all to 1 or 2." << endl;
	cout << "This was done to compare the speed of the different methods of matrix multiplication." << endl;
	cout << "To change this to make it user input, uncomment the user input promts." << endl;
	cout << "The answer has also been commented out to prevent printing 700 x 700 values." << endl;

	populating_matrix_1(row1, col1);
	populating_matrix_2(row2, col2);
	populating_mult_matrix(row1, col2);

	multiply_ijk(row1, col1, row2, col2);
	multiply_jki(row1, col1, row2, col2);
	multiply_kij(row1, col1, row2, col2);
	transposed_method(row1, col1, row2, col2);

	//printing_answer(row1, col2);

	system("PAUSE");
	return 0;
}
