#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include <time.h>

int main()
{
    const int N = 5;
    srand(time(NULL));

    matrix M = new_matrix(N, N);
    for(int i=1; i<=N; i++ )
        for (int j=1; j<=i; j++ )
        {   
            if (j==i) { mget(M,i,j) = i*2.1; }
            else
            {
                mget(M,i,j) = (rand() % 100000 + 1) / 100000.0;
            }
        }

    print_matrix(&M);

    vector v = new_vector(N);
    for (int i=1; i<=N; i++)
    { vget(v,i) = rand(); }

    double res = power_iteration(&v, &M, 1.0e-6, 100);
    printf("  The largest eigen value of this matrix is %3.3f.\n\n", res);

    for (double mu=0; mu<=15; mu+=3)
    {
        v = new_vector(N);
        for (int i=1; i<=N; i++)
        { vget(v,i) = rand(); }

        double res2 = shifted_inverse_power_iteration(mu, &v, &M, 1.0e-6, 100);
        printf("  The eigen value closest to %3.3f is %3.3f.\n", mu, res2);
    }

    v = new_vector(N);
    for (int i=1; i<=N; i++)
    { vget(v,i) = rand(); }

    double res3 = rayleigh_quotient_iteration(&v, &M, 1.0e-6, 100);
    printf("  The random eigen value is %3.3f.\n", res3);

    v = new_vector(N);
    for (int i=1; i<=N; i++)
    { vget(v,i) = rand(); }

    res3 = rayleigh_quotient_iteration(&v, &M, 1.0e-6, 100);
    printf("  The random eigen value is %3.3f.\n", res3);
}