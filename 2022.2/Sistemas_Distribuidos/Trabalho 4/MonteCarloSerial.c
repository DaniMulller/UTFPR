// mpicc MonteCarloPararelo.c -o MonteCarloPararelo
// mpirun -np 16 --oversubscribe MonteCarloPararelo
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
    long int i, sum = 0, accum = 0, interations = 10000000000;
    double pi = 0.0, begin = 0.0, end = 0.0, x, y, z;
    
    for (i = 0; i < interations; i ++) {
        x = rand() / (RAND_MAX + 1.0);
        y = rand() / (RAND_MAX + 1.0);
        z = ((x*x)+(y*y));
        
        if(z <= 1.0) 
        {
            sum++;
        }
    }
    
    pi =  (1E-8 * accum)/10;
    printf("Processadores = 1;    PI = %0.10f\n", pi);
    
    return 0;
}