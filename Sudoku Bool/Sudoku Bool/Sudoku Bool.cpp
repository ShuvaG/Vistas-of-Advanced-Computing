// Sudoku Assignment
// Shuva Gautam and Surbhi Gupta

#include <iostream>
using namespace std;
int grid[9][9] = {
	{ 0,0,5,3,0,0,0,0,0 },
{ 8,0,0,0,0,0,0,2,0 },
{ 0,7,0,0,1,0,5,0,0 },
{ 4,0,0,0,0,5,3,0,0 },
{ 0,1,0,0,7,0,0,0,6 },
{ 0,0,3,2,0,0,0,8,0 },
{ 0,6,0,5,0,0,0,0,9 },
{ 0,0,4,0,0,0,0,3,0 },
{ 0,0,0,0,0,9,7,0,0 } };
void print_game()
{
	for (int row= 0;row< 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			if (grid[row][col] == 0)
				cout << "." << " ";
			else
				cout << grid[row][col] << " ";
		}
		cout << endl;
	}
}

bool conditions(int row, int col, int n) // This will check to see if there are duplicates
{
	int row_beginning, col_beginning;
	row_beginning = row - row % 3; // The modulo will change the number by box size (each box is a 3 x 3)
	col_beginning = col - col % 3;

	for (int col = 0; col < 9; col++)
	{
		if (grid[row][col] == n)
			return true; // Indicates duplicate in the ROW
	}
	for (int row = 0; row < 9; row++)
	{
		if (grid[row][col] == n)
			return true; // Indicates duplicate in the COLUMN
	}
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)

		{
			if (grid[row + row_beginning][col + col_beginning] == n) // Indicated douplicate in the BOX
				return true;
		}
	}
	return false;
}

bool check_zeros(int &row, int &col) // Passing by reference because we want to save this row and col value
{
	for (row = 0; row < 9; row++)
	{
		for (col = 0; col < 9; col++)
		{
			if (grid[row][col] == 0)
				return true;
		}
	}
	return false;
}
bool Sudoku_solver()
{
	int row, col, counter = 0;
	if (check_zeros(row, col)==false) // This checks to find zeros. If there is a zero, the row and col value will be stored.
		return true; // Number already exists, don't use this row/col value
	{
		for (int n = 1; n <= 9; n++) {
			if (conditions(row,col, n)==false) {
				grid[row][col] = n;
				if (Sudoku_solver())
					return true;
				grid[row][col] = 0;
			}
		}
	}
	return false;
}
int main()
{
	int ans;
	cout << "The Entered Sudoku puzzle is:" << endl;
	print_game();
	cout << "Print '0' to confirm and solve, or '1' to exit:" << endl;
	cin >> ans;
	if (ans == 0)
	{
		if (Sudoku_solver())
		{
			cout << "The solution to this game is:" << endl;
			for (int row= 0; row< 9; row++)
			{
				for (int col = 0; col < 9; col++)
					cout << grid[row][col] << " ";
				cout << endl;
			}
		}
	}
	if (ans == 1) exit(0);
	system("PAUSE");
	return 0;
}