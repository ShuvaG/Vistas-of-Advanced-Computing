// Pi Monte Carlo

#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

void pi_double()
{
	double x_rand, y_rand, distance;
	double circle = 0;
	double square = 0;
	double pi;
	int i, j, n;
	srand(time(0));
	cout << "----------Estimating with double----------" << endl;
	for (i = 1; i < 9; i++)
	{
		circle = 0;
		square = 0;
		n = pow(10, i);
		for (j = 0; j < n; j++)
		{
			x_rand = (double)rand() / RAND_MAX;
			y_rand = (double)rand() / RAND_MAX;
			distance = x_rand * x_rand + y_rand * y_rand;
			if (distance <= 1)
			{
				circle += 1;
				square += 1;
			}
			if (distance > 1)
				square += 1;
		}
		cout << "Circle: " << circle << endl;
		cout << "Square: " << square << endl;
		pi = 4 * (circle / square);
		cout << fixed;
		cout << setprecision(i);
		cout << "Pi(" << i << " decimal places): " << pi << endl << endl;
		cout << fixed;
		cout << setprecision(0);
	}
}

void pi_float()
{
	float x_rand, y_rand, distance;
	float circle = 0;
	float square = 0;
	float pi;
	int i, j, n;
	srand(time(0));
	cout << "----------Estimating wih float----------" << endl;
	for (i = 1; i <= 8; i++)
	{
		circle = 0;
		square = 0;
		n = pow(10, i);
		for (j = 0; j < n; j++)
		{
			x_rand = (float)rand() / RAND_MAX;
			y_rand = (float)rand() / RAND_MAX;
			distance = x_rand * x_rand + y_rand * y_rand;
			if (distance <= 1)
			{
				circle += 1;
				square += 1;
			}
			if (distance > 1)
				square += 1;
		}
		cout << "Circle: " << circle << endl;
		cout << "Square: " << square << endl;
		pi = 4 * (circle / square);
		cout << fixed;
		cout << setprecision(i);
		cout << "Pi(" << i << " decimal places): " << pi << endl << endl;
		cout << fixed;
		cout << setprecision(0);
	}
}

int main()
{
	pi_double();
	pi_float();
	system("PAUSE");
	return 0;
}