// Argon Molecular Dynamics

#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
using namespace std;

// VARIABLES TO CHANGE
const int dimension = 5;    // Dimensions of the particles
const int N = 125;         // Number of particles ( dimensions^3)
int box = 6;                // Box size

ofstream p_energy("PotentialEnergy.txt");
ofstream total_energy("TotalEnergy.txt");
ofstream k_energy("KineticEnergy.txt");
ofstream temperature("Temperature.txt");
int num_particles = pow(dimension, 3);
double t = 0;
double dt = .005;
double tmax = 20;
double temp = 1;
double sigma = 1;
double f[N][3], v[N][3], x[N][3], xm[N][3]; 
double x_sumv = 0, y_sumv = 0, z_sumv = 0, sumv2 = 0;
double en, etot;

void lattice_pos(int i) // assigning each particle a x, y, and z coordinate.
{
	x[i][2] = (i / (int)pow(dimension, 2));
	x[i][1] = (i - (int)pow(dimension, 2)*(int)x[i][2]) / dimension;
	x[i][0] = (i - (int)pow(dimension, 2)*(int)x[i][2] - dimension * (int)x[i][1]);

	x[i][2] = x[i][2] * box / dimension;
	x[i][1] = x[i][1] * box / dimension;
	x[i][0] = x[i][0] * box / dimension;

	x[i][0] = x[i][0] - box * round(x[i][0] / box);
	x[i][1] = x[i][1] - box * round(x[i][1] / box);
	x[i][2] = x[i][2] - box * round(x[i][2] / box);
}

void initialization()
{
	double x_sumv = 0, y_sumv = 0, z_sumv = 0;
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
	fs = sqrt(3 * temp / sumv2);
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

void force()
{
	double rc = 4*sigma;
	double rc2 = rc*rc;
	double x_xr, y_xr, z_xr, x_r2, y_r2, z_r2, r2, r2i, r6i, ff;
	double ecut = 4 *( pow(rc, -12) - pow(rc, -6));
	en = 0;
	for (int i = 0; i < num_particles; i++)
	{
		f[i][0] = 0;
		f[i][1] = 0;
		f[i][2] = 0;
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			x_xr = x[i][0] - x[j][0]; // distance between the two
			y_xr = x[i][1] - x[j][1]; 
			z_xr = x[i][2] - x[j][2]; 

			x_xr -=box * round(x_xr / box); // periodic boundary condition
			y_xr -=box * round(y_xr / box);
			z_xr -=box * round(z_xr / box);

			r2 = pow(x_xr, 2) + pow(y_xr, 2) + pow(z_xr, 2);
			if (r2<rc2) // test cutoff
			{
				r2i = 1 / r2; // inverse of r2
				r6i = pow(r2i, 3);
				ff = 48 * r2i*r6i*(r6i - .5);
				f[i][0] += ff * x_xr;
				f[j][0] -= ff * x_xr;
				f[i][1] += ff * y_xr;
				f[j][1] -= ff * y_xr;
				f[i][2] += ff * z_xr;
				f[j][2] -= ff * z_xr;
				en += 4 * r6i*(r6i - 1) - ecut;
			}		
		}
	}
}

void integrate()
{
	double xx, yy, zz, x_vi, y_vi, z_vi;
	x_sumv = 0;
	y_sumv = 0;
	z_sumv = 0;
	sumv2 = 0;
	for (int i = 0; i < num_particles; i++)
	{
		xx = 2 * x[i][0] - xm[i][0] + pow(dt, 2)*f[i][0];
		yy = 2 * x[i][1] - xm[i][1] + pow(dt, 2)*f[i][1];
		zz = 2 * x[i][2] - xm[i][2] + pow(dt, 2)*f[i][2];

		x_vi = (xx - xm[i][0]) / (2 * dt); // velocity
		y_vi = (yy - xm[i][1]) / (2 * dt);
		z_vi = (zz - xm[i][2]) / (2 * dt);

		x_sumv += x_vi; // velocity center of mass
		y_sumv += y_vi;
		z_sumv += z_vi;

		sumv2 += pow(x_vi,2) + pow(y_vi,2) + pow(z_vi, 2); // total kinetic energy

		xm[i][0] = x[i][0];
		xm[i][1] = x[i][1];
		xm[i][2] = x[i][2];

		x[i][0] = xx;
		x[i][1] = yy;
		x[i][2] = zz;
		
		xm[i][0] = xm[i][0] - box * round(x[i][0] / box);
		xm[i][1] = xm[i][1] - box * round(x[i][1] / box);
		xm[i][2] = xm[i][2] - box * round(x[i][2] / box);

		x[i][0] = x[i][0] - box * round(x[i][0] / box);
		x[i][1] = x[i][1] - box * round(x[i][1] / box);
		x[i][2] = x[i][2] - box * round(x[i][2] / box);

	}
	temp = sumv2 / (3.0 * num_particles); // instantaneous temperature
	etot = (en + .5 * sumv2) / num_particles; // total energy per particle
	k_energy << sumv2 << " ";
	p_energy << en << " ";
	total_energy << etot << " ";
	temperature << temp << " ";
}

int main()
{
	ofstream ATOM_125("ATOM125.xyz");
	ofstream time("Time.txt");
	int count = 0;
	int i = 0;

	cout << "If you wish the change the number of particles or box size," << endl;
	cout << "please change the three global variables under VARIABLES TO CHANGE." << endl << endl;
	cout << "Please wait as files are being written." << endl;

	ATOM_125 << N << endl;
	ATOM_125 << endl;

	initialization();
	for (int i = 0; i < N; i++)
		ATOM_125 << "ATOM" + to_string(i + 1) + " " << x[i][0] << " " << x[i][1] << " " << x[i][2] << endl;
	while (t < tmax)
	{
		force();
		integrate();
		if (count % 4 == 0)
		{
			for (int i = 0; i < N; i++)
				ATOM_125 << "ATOM" + to_string(i + 1) + " " << x[i][0] << " " << x[i][1] << " " << x[i][2] << endl;
		}
		time << t << " ";
		count++;
		t += dt;
		i++;
	}

	ATOM_125.close();
	p_energy.close();
	k_energy.close();
	total_energy.close();
	temperature.close();
	time.close();
																																																																																																										
	system("PAUSE");
	return 0;
}