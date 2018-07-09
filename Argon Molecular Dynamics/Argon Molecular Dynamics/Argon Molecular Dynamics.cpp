// Argon Molecular Dynamics

#include <iostream>
#include <math.h>
using namespace std;

double t = 0;
double tmax = 1;  // ?????????????????????
int num_particles = 1000;
const int N = 1000;
const int dimension = 10;
double f[N][3], v[N][3], x[N][3], xm[N][3]; // 2D array will make it 3D
double x_sumv = 0, y_sumv = 0, z_sumv = 0, sumv2 = 0;
double temp = 1, en;
double dt = .0005;
int box = 11;

void lattice_pos(int i) // assigning each particle a x, y, and z coordinate.
{
	x[i][2] = (i / (int)pow(dimension, 2));
	x[i][1] = (i - (int)pow(dimension, 2)*(int)x[i][2]) / dimension;
	x[i][0] = (i - (int)pow(dimension, 2)*(int)x[i][2] - dimension * (int)x[i][1]);

	//x[i][2] = x[i][2] * box / dimension;
	//x[i][1] = x[i][1] * box / dimension;
	//x[i][0] = x[i][0] * box / dimension;
}

void initialization()
{
	double x_sumv = 0, y_sumv = 0, z_sumv = 0;
	double sumv2 = 0;
	double fs;
	for (int i = 0; i < num_particles; i++)
	{
		lattice_pos(i);
		v[i][0] = (rand() / (double)RAND_MAX) - .5;
		v[i][1] = (rand() / (double)RAND_MAX) - .5;
		v[i][2] = (rand() / (double)RAND_MAX) - .5;
		x_sumv += v[i][0];
		y_sumv += v[i][1];
		z_sumv += v[i][2];
		sumv2 += pow(v[i][0], 2) + pow(v[i][1], 2) + pow(v[i][2], 2);
	}
	x_sumv /= num_particles;
	y_sumv /= num_particles;
	z_sumv /= num_particles;
	sumv2 /= num_particles;
	fs = pow(3 * temp / sumv2, .5);
	for (int i = 0; i < num_particles; i++)
	{
		v[i][0] = (v[i][0] - x_sumv) * fs; // rescaling
		v[i][1] = (v[i][1] - y_sumv) * fs;
		v[i][2] = (v[i][2] - z_sumv) * fs;
		xm[i][0] = x[i][0] - v[i][0] * dt;
		xm[i][1] = x[i][1] - v[i][1] * dt;
		xm[i][2] = x[i][2] - v[i][2] * dt;
	}
}

void force(double f[N][3], double en)
{
	double r2c = dimension / 2;
	double xr, r2, r2i, r6i, ff;
	double box = 1; // ???????????????????????
	double ecut = 1; // ?????????????????????
	en = 0;
	for (int i = 0; i < num_particles; i++)
	{
		f[i][0] = 0;
		f[i][1] = 0;
		f[i][2] = 0;
	}
	for (int i = 0; i < num_particles - 1; i++)
	{
		for (int j = i + 1; j < num_particles; j++)
		{
			xr = sqrt((pow(x[i][0] - x[j][0], 2) + pow(x[i][1] - x[j][1], 2) - pow(x[i][2] - x[j][2], 2)));
			xr = xr - box * int(xr / box); // periodic boundary condition
			cout << "xr: " << xr << endl;
			r2 = pow(xr, 2);
			if (r2 < r2c)
			{
				r2i = 1 / r2;
				r6i = pow(r2i, 3);
				ff = 48 * r2i*r6i*(r6i - .5);
				f[i][0] = f[i][0] + ff * xr;
				f[j][0] = f[j][0] - ff * xr;
				f[i][1] = f[i][1] + ff * xr;
				f[j][1] = f[j][1] - ff * xr;
				f[i][2] = f[i][2] + ff * xr;
				f[j][2] = f[j][2] - ff * xr;
				en = en + 4 * r6i*(r6i - 1) - ecut;
			}
		}
	}
}

void integrate(double f[N][3], double en)
{
	double etot, xx, yy, zz, x_vi, y_vi, z_vi;
	for (int i = 0; i < num_particles; i++)
	{
		xx = 2 * x[i][0] - xm[i][0] + pow(dt, 2)*f[i][0];
		yy = 2 * x[i][1] - xm[i][1] + pow(dt, 2)*f[i][1];
		zz = 2 * x[i][2] - xm[i][2] + pow(dt, 2)*f[i][2];
		x_vi = (xx - xm[i][0]) / (2 * dt);
		y_vi = (yy - xm[i][1]) / (2 * dt);
		z_vi = (zz - xm[i][2]) / (2 * dt);
		x_sumv += x_vi; // velocity center of mass
		y_sumv += y_vi;
		z_sumv += z_vi;
		sumv2 += pow((x_vi + y_vi + z_vi), 2); // total kinetic energy
		xm[i][0] = x[i][0];
		xm[i][1] = x[i][1];
		xm[i][2] = x[i][2];
		x[i][0] = xx;
		x[i][1] = yy;
		x[i][2] = zz;
	}
	temp = sumv2 / (3 * num_particles); // instantaneous temperature
	etot = (en + .5 * sumv2) / num_particles; // total energy per particle
}

int main()
{
	int i = 0;
	initialization();
	for (int i = 0; i < N; i++)
		cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << endl;
	while (t < tmax)
	{
		force(f, en);
		integrate(f, en);
		t += dt;
		i++;
	}

	system("PAUSE");
	return 0;
}