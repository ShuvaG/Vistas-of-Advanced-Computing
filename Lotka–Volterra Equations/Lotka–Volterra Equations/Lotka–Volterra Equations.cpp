// Lotka–Volterra Equations

#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

double alpha = 1.5;      // rate of prey population increase
double beta = 3;       // predation rate coefficient
double delta = 1;      // reproduction rate of the predators per prey eaten
double gamma = 1;      // predator mortality rate

double kappa = .1;     // constants for damped version
double lambda = .1;    // constants for damped version

const int n = 9000;    // array size
double x[n];           // number of prey
double y[n];           // number of predators
double dt = .1;        // time step
double x_star;         // intermediate prey value
double y_star;         // intermediate predator value

double fx(double x, double y) { return alpha * x - beta * x * y; }     // regular version
double fy(double x, double y) { return delta * x * y - gamma * y; }    // regular version

//double fx(double x, double y) { return alpha*x - lambda * x * x - beta * x * y; }    // damped version
//double fy(double x, double y) { return delta * x * y - kappa * y * y - gamma * y; }  // damped version

int main()
{
	x[0] = 5;   // initial prey population
	y[0] = 5;  // initial predetor population

	ofstream prey("prey.txt");           // writing to file
	ofstream predator("predator.txt");   // writing to file

	for ( int i = 0; i < n ; i++)
	{
		prey << x[i] << " ";
		predator << y[i] << " ";

		x_star = x[i] + dt * fx(x[i], y[i]);                                     // intermediate prey value
		y_star = y[i] + dt * fy(x[i], y[i]);                                     // intermediate predator value
		x[i + 1] = x[i] + dt * 1 / 2 * (fx(x[i], y[i]) + fx(x_star, y_star));    // updated prey value
		y[i + 1] = y[i] + dt * 1 / 2 * (fy(x[i], y[i]) + fy(x_star, y_star));    // updated predator value

	}
	prey.close();
	predator.close();
	system("PAUSE");
	return 0;
}