// Estimating Pi
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	double pi = 0;
	double pi_total;
	double dx = .00001;
	int c = 0;
	int rank, size, total;

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	const clock_t begin_time = clock();
	for (double x = rank*dx; x < 1; x+=dx*size)
	{
		pi += dx * 4 / (1 + x * x);
	}
	const clock_t end_time = clock();
	int total_time, tot;
	total_time = end_time - begin_time;
	MPI_Reduce(&pi, &pi_total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Reduce(&total_time, &tot, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if (rank == 0)
	{
		printf("Estimated value of pi is %f.\n", pi_total);
		printf("It took %d seconds.\n", total_time);
	}
	MPI_Finalize();
	system("PAUSE");
	return 0;
}