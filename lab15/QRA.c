#include <stdlib.h>
#include <assert.h>
#include "trimatrix.h"
#include <math.h>

void QRA(trimatrix* T, int t)
{
    /*
    The QR Algorithm to get the diagonal matrix of eigenvalues.
    Input:
        T:  Matrix in Tridiagonal form. trimatrix
        t:  The total times of QRA have been applied. int
    Output:
        No output.
    */

    // function declarations
    matrix QRdecomp(matrix* A);

    // get size
    const int N = T->rows; assert(N==T->cols);

    if (N==1)
    { return; }
    else
    {
        // Copy tridiagonal matrix into a bigger
        // matrix -- needed for QR step
        matrix R = new_matrix(N,N);
        mget(R,1,1) = tget(T,1,1);
        mget(R,1,2) = tget(T,1,2);
        for (int i=2; i<=(N-1); i++)
        {
            mget(R,i,i-1) = tget(T,i,i-1);
            mget(R,i,i) = tget(T,i,i);
            mget(R,i,i+1) = tget(T,i,i+1);
        }
        mget(R,N,N-1) = tget(T,N,N-1);
        mget(R,N,N) = tget(T,N,N);
        
        // QR factorization on bigger matrix
        matrix Q = QRdecomp(&R);

        // Multiply Q and R in reverse order
        // and store in a new tridiagonal matrix
        delete_trimatrix(T);
        *T = matrix_mult_to_trimatrix(&R,&Q);

        // check whether the matrix T is good enough
        double resid = 0;
        for (int i=2; i<=N; i++)
        {
            resid += fabs(tget(T, i, i-1));
            resid += fabs(tget(T, i-1, i));            
        }

        // Recursive call to QR algorithm
        if (t<10000 && resid > 1e-16)
        { QRA(T, t+1); }
    }
}
