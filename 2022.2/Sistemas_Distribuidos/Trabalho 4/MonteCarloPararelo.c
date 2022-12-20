// mpicc MonteCarloPararelo.c -o MonteCarloPararelo
// mpirun -np 16 --oversubscribe MonteCarloPararelo
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

int main (int argc, char* argv[]) {
    int rank, size;
    long int i, sum = 0, accum = 0, interations = 10000000000;
    double pi = 0.0, begin = 0.0, end = 0.0, x, y, z;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    begin = MPI_Wtime();
    
    srand((int)time(0));
    
    for (i = rank; i < interations; i += size) {
        x = rand() / (RAND_MAX + 1.0);
        y = rand() / (RAND_MAX + 1.0);
        z = ((x*x)+(y*y));
        
        if(z <= 1.0) 
        {
            sum++;
        }
    }

    MPI_Reduce(&sum, &accum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);

    end = MPI_Wtime();
    
    if (rank == 0)
    {
        pi =  (1E-8 * accum)/10;
        printf("Processadores = %2d;    Tempo = %f s;    PI = %0.10f\n", size, end-begin, pi);
    }
    
    MPI_Finalize();
    
    return 0;
}