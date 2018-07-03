// Game of Life 
#include <iostream>
#include<windows.h>
#include<ctime>
#include<conio.h>
using namespace std;

int const A = 100; // dimensions of the matrix
int matrix[A][A];
int matrix_copy[A][A];
int sum = 0;

void check_matrix(int row, int col)
{
	if (matrix[row][col] == 1 && sum < 2)
	{
		matrix_copy[row][col] = 0;
		return;
	}
	else if (matrix[row][col] == 1 && sum >= 2 && sum <= 3)
	{
		matrix_copy[row][col] = 1;
		return;
	}
	else if (matrix[row][col] == 1 && sum > 3)
	{
		matrix_copy[row][col] = 0;
		return;
	}
	else if (matrix[row][col] == 0 && sum == 3)
	{
		matrix_copy[row][col] = 1;
		return;
	}
	else
	{
		matrix_copy[row][col] = 0;
		return;
	}
}

int main()
{
	int N; // decides the number of iterations
	int n;
	cout << "Enter the dimensions of the square matrix: ";
	cin >> n;
	cout << "How many iterations do you want? ";
	cin >> N;

	srand(time(0));

	for (int row = 0; row < n; row++) // populates the matrix
	{
		for (int col = 0; col < n; col++)
			matrix[row][col] = rand() % 2; // randomized each location with a 1 or 0
	}

	for (int i = 0; i < N; i++)
	{
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				sum = 0;
				if (row == 0 && col == 0) // checks top left corner
				{
					sum = matrix[row + 1][col] + matrix[row][col + 1] + matrix[row + 1][col + 1] + matrix[row + 1][n - 1] + matrix[row][n - 1] + matrix[n - 1][n - 1] + matrix[n - 1][col] + matrix[n - 1][col + 1];
					check_matrix(row, col);
				}
				if (row == 0 && col > 0 && col < n - 1) // check top row
				{
					sum = matrix[row][col - 1] + matrix[row][col + 1] + matrix[row + 1][col - 1] + matrix[row + 1][col] + matrix[row + 1][col + 1] + matrix[n - 1][col - 1] + matrix[n - 1][col] + matrix[n - 1][col + 1];
					check_matrix(row, col);
				}
				if (row == 0 && col == n - 1) // check top right corner
				{
					sum = matrix[row][col - 1] + matrix[row + 1][col - 1] + matrix[row + 1][col] + matrix[n - 1][col - 1] + matrix[n - 1][col] + matrix[n - 1][0] + matrix[row][0] + matrix[row + 1][0];
					check_matrix(row, col);
				}
				if (row == n - 1 && col == 0) // checks bottom left corner
				{
					sum = matrix[row - 1][col] + matrix[row - 1][col + 1] + matrix[row][col + 1] + matrix[0][col + 1] + matrix[0][col] + matrix[0][n - 1] + matrix[n - 1][n - 1] + matrix[row - 1][n - 1];
					check_matrix(row, col);
				}
				if (row == n - 1 && col > 0 && col < n - 1) // check bottom row
				{
					sum = matrix[row][col - 1] + matrix[row - 1][col - 1] + matrix[row - 1][col] + matrix[row - 1][col + 1] + matrix[row][col + 1] + matrix[0][col - 1] + matrix[0][col] + matrix[0][col + 1];
					check_matrix(row, col);
				}
				if (row == n - 1 && col == n - 1) // check bottom corner
				{
					sum = matrix[row][col - 1] + matrix[row - 1][col - 1] + matrix[row - 1][col] + matrix[row - 1][0] + matrix[row][0] + matrix[0][0] + matrix[0][col] + matrix[0][col - 1];
				}
				if (row > 0 && row < n - 1 && col > 0 && col < n - 1) // checks middle part
				{
					sum = matrix[row][col - 1] + matrix[row - 1][col - 1] + matrix[row - 1][col] + matrix[row - 1][col + 1] + matrix[row][col + 1] + matrix[row + 1][col + 1] + matrix[row + 1][col] + matrix[row + 1][col - 1];
					check_matrix(row, col);
				}
				if (row > 0 && row < n - 1 && col == 0) // checks left column
				{
					sum = matrix[row - 1][col] + matrix[row - 1][col + 1] + matrix[row][col + 1] + matrix[row + 1][col + 1] + matrix[row + 1][col] + matrix[row - 1][n - 1] + matrix[row][n - 1] + matrix[row + 1][n - 1];
					check_matrix(row, col);
				}
				if (row > 0 && row < n - 1 && col == n - 1) // check right column
				{
					sum = matrix[row - 1][col] + matrix[row - 1][col - 1] + matrix[row][col - 1] + matrix[row + 1][col - 1] + matrix[row + 1][col] + matrix[row - 1][0] + matrix[row][0] + matrix[row + 1][0];
					check_matrix(row, col);
				}
			}
		}
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				matrix[row][col] = matrix_copy[row][col];
			}
		}
		for (int row = 0; row < n; row++) // displays the matrix
		{
			for (int col = 0; col < n; col++)
			{
				if (matrix[row][col] == 1)
					cout << "x ";
				else
					cout << ". ";
			}
			cout << endl;
		}
		cout << endl;
		Sleep(1000);
		system("cls");
	}

	system("PAUSE");
	return 0;
}