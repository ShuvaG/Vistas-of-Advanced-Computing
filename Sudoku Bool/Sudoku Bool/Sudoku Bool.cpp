// Sudoku Assignment
// Shuva Gautam and Surbhi Gupta
/*NOTE = We tried our absolute hardest to debug our logic, but were not able to find the source of our faulty logic. 
         The final solutions have zeros in matrix, but all of the other Sudoku guidelines still work. 
		 There are just numbers from 0-9 instead of 1-9.*/

#include <iostream>
using namespace std;
int grid[9][9] = {
{ 1,0,5,3,0,7,0,9,8 },
{ 8,0,0,0,0,0,0,2,0 },
{ 0,7,0,0,1,0,5,0,0 },
{ 4,0,6,0,0,5,3,0,2 },
{ 0,1,0,0,7,0,0,0,6 },
{ 0,0,3,2,0,0,0,8,0 },
{ 0,6,0,5,0,2,0,0,9 },
{ 0,0,4,0,0,0,0,3,0 },
{ 0,2,0,8,0,9,7,0,0 } };
void print_game()
{
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			if (grid[r][c] == 0)
				cout << "." << " ";
			else
				cout << grid[r][c] << " ";
		}
		cout << endl;
	}
}
bool check_row(int r, int n) // This will check to see if there are duplicates in the row
{
	for (int c = 0; c < 9; c++)
	{
		if (grid[r][c] == n)
			return true; // Indicates duplicate
	}
	return false;
}
bool check_col(int c, int n) // This checks if there is a duplicate number in the column
{
	for (int r = 0; r < 9; r++)
	{
		if (grid[r][c] == n)
		{
			return true; // Indicates duplicate
		}
	}
	return false;
}
bool check_box(int row, int col, int n)
{
	int block = (row / 3) * 3 + (col / 3);
	switch (block)
	{
	case 0:
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				if (grid[r][c] == n)
					return true; // Indicates duplicate
			}
		}
		return false;
	case 1:
		for (int r = 0; r < 3; r++)
		{
			for (int c = 3; c < 6; c++)
			{
				if (grid[r][c] == n)
					return true; // Indicates duplicate
			}
		}
		return false;
	case 2:
		for (int r = 0; r < 3; r++)
		{
			for (int c = 6; c < 9; c++)
			{
				if (grid[r][c] == n)
					return true; // Indicates duplicate
			}
		}
		return false;
	case 3:
		for (int r = 3; r < 6; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				if (grid[r][c] == n)
					return true; // Indicates duplicate
			}
		}
		return false;
	case 4:
		for (int r = 3; r < 6; r++)
		{
			for (int c = 3; c < 6; c++)
			{
				if (grid[r][c] == n)
					return true; // Indicates duplicate
			}
		}
		return false;
	case 5:
		for (int r = 3; r < 6; r++)
		{
			for (int c = 6; c < 9; c++)
			{
				if (grid[r][c] == n)
					return true; // Indicates duplicate
			}
		}
		return false;
	case 6:
		for (int r = 6; r < 9; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				if (grid[r][c] == n)
					return true; // Indicates duplicate
			}
		}
		return false;
	case 7:
		for (int r = 6; r < 9; r++)
		{
			for (int c = 3; c < 6; c++)
			{
				if (grid[r][c] == n)
					return true; // Indicates duplicate
			}
		}
		return false;
	case 8:
		for (int r = 6; r < 9; r++)
		{
			for (int c = 6; c < 9; c++)
			{
				if (grid[r][c] == n)
					return true; // Indicates duplicate
			}
		}
		return false;
	}
	return false;
}
bool Sudoku_solver()
{
	int r, c, counter = 0;
	for (r = 0; r < 9; r++) // FINDING ZERO
	{
		for (c = 0; c < 9; c++)
			if (grid[r][c] == 0) counter++; // Counts how many zeros there are.
	}
	if (counter == 0) return true;
	if (counter != 0)
	{
		for (r = 0; r < 9; r++) // REASSIGNING ZEROS
		{
			for (c = 0; c < 9; c++)
			{
				if (grid[r][c] == 0)
				{
					for (int n = 1; n < 10 ; n++) // This will assign a number to each zero.
					{
						if (check_row(r, n) == false && check_col(c, n) == false && check_box(r, c, n) == false) // This checks to see if it is not a duplicate number
						{
							grid[r][c] = n;
							if (Sudoku_solver()) // This is a recursive process to fill in the empty spaces.
								return true;
							else grid[r][c] = 0;
						}
					}
				}
			}
		}
	}
	return true;
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
			for (int r = 0; r < 9; r++)
			{
				for (int c = 0; c < 9; c++)
					cout << grid[r][c] << " ";
				cout << endl;
			}
		}
	}
	if (ans == 1) exit(0);
	system("PAUSE");
	return 0;
}