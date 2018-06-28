// THOMAS ALGORITHM

#include <iostream>
using namespace std;

int main()	
{
	const int N = 2;
	double alpha[N], g[N], a, b, c, f[N], u[N], un[N];
	
	a = 3;
	b = -1;
	c = -1;
	f[0] = -1;
	f[1] = 7;
	f[2] = 7;


	alpha[0] = a;
	g[0] = f[0];
	u[0] = 0;

	for (int j = 1; j <=N; j++)
	{
		alpha[j] = a - (b / alpha[j - 1])*c;
		g[j] = f[j] - (b / alpha[j - 1])*g[j - 1];
		u[j] = g[j] / alpha[j];
	}

	for (int k = N-1; k >= 0; k--)
	{
		u[k] = (g[k] - c * u[k + 1]) / alpha[k];
	}

	cout << "The values of u are: " << endl << u[0] << endl << u[1] << endl << u[2] << endl;

	int j;
	cin >> j;

	return 0;
}
