// Even/Odd Numbers

#include "mpi.h"
#include <ctime>
using namespace std;

int main()
{
	int number = 200000;
	int c = 0;
	int rank, size, total;

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	const clock_t begin_time = clock();
	for (int j = rank + 2; j < number; j += size)
	{
		for (int i = 2; i < j; i++)
		{
			if (j%i == 0) // means it's not a prime number
			{
				c--;
				break;
			}
		}
		c++;
	}
	const clock_t end_time = clock();
	int total_time, tot;
	total_time = end_time - begin_time;
	MPI_Reduce(&c, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Reduce(&total_time, &tot, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if (rank == 0)
	{
		printf("There are %d prime numbers.\n", total);
		printf("It took %d seconds.\n", total_time);
	}
	MPI_Finalize();
	return 0;
}
