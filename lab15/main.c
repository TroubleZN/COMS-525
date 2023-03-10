#include <stdlib.h>
#include <stdio.h>
#include "trimatrix.h"
#include <time.h>
#include <assert.h>

int main()
{   
    srand( time(NULL) );
    int N=0;
    printf(" Input N: ");
    scanf("%i",&N);
    assert(N>1);

    // Create a random symmetric matrix
    matrix A = new_matrix(N,N);

    for (int i=1; i<=N; i++)
        for (int j=1; j<=i; j++)
        {
            double tmp = ((double)rand())/((double)RAND_MAX);
            tmp = (double)((int)(10000.0*tmp))/10000.0;
            mget(A,i,j) = tmp;
        }
    for (int i=1; i<=(N-1); i++)
        for (int j=(i+1); j<=N; j++)
        { mget(A,i,j) = mget(A,j,i); }
        
    // Hessenberg reduction to tridiagonal form
    trimatrix T = new_trimatrix(N);
    void Hessenberg(const matrix* A, trimatrix* T);
    Hessenberg(&A,&T);
    printf("\n");
    printf("Original Matrix:\n");
    print_matrix(&A);
    printf("Reduction to Tridiagonal Form:\n");
    print_trimatrix(&T);

    // QR Algorithm to find eigenvalues of T
    // which are the same as the eigenvalues of A
    void QRA(trimatrix* T, int t);
    QRA(&T, 0);
    printf("After QR Algorithm:\n");
    print_trimatrix(&T);

    printf("Here we use shifted inverse power iteration to validate the results.\n");
    vector v = new_vector(N);
    for (int i=1; i<=N; i++)
    { vget(v,i) = rand(); }

    double res = shifted_inverse_power_iteration(tget(&T, 1, 1), &v, &A, 1.0e-6, 100);
    printf("The eignvalue of A closest to T[1,1] is %f.\n", res);

    res = shifted_inverse_power_iteration(tget(&T, 2, 2), &v, &A, 1.0e-6, 100);
    printf("The eignvalue of A closest to T[2,2] is %f.\n", res);

    res = shifted_inverse_power_iteration(tget(&T, 3, 3), &v, &A, 1.0e-6, 100);
    printf("The eignvalue of A closest to T[3,3] is %f.\n", res);

    res = shifted_inverse_power_iteration(tget(&T, 4, 4), &v, &A, 1.0e-6, 100);
    printf("The eignvalue of A closest to T[4,4] is %f.\n", res);

    res = shifted_inverse_power_iteration(tget(&T, 5, 5), &v, &A, 1.0e-6, 100);
    printf("The eignvalue of A closest to T[5,5] is %f.\n", res);

    res = shifted_inverse_power_iteration(tget(&T, 6, 6), &v, &A, 1.0e-6, 100);
    printf("The eignvalue of A closest to T[6,6] is %f.\n", res);
}