// Pi Monte Carlo

#include "mpi.h"
#include <time.h>
#include <math.h>

int main()
{
	double x_rand, y_rand, distance;
	double circle = 0;
	double square = 0;
	double circle_total, square_total, pi_total;
	double pi;
	int n = 10000000000;

	int rank, size, total;
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	const clock_t begin_time = clock();
	for (int j = 0; j < n; j++)
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
	const clock_t end_time = clock();
	int total_time, tot;
	total_time = end_time - begin_time;
	MPI_Reduce(&circle, &circle_total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Reduce(&square, &square_total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Reduce(&total_time, &tot, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if (rank == 0)
	{
		pi = 4 * (circle_total / square_total);
		printf("Estimated value of pi is %f.\n", pi_total);
		printf("It took %d seconds.\n", total_time);
	}
	MPI_Finalize();
	return 0;
}
