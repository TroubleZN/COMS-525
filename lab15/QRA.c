#include <stdlib.h>
#include <assert.h>
#include "trimatrix.h"

void QRA(trimatrix* T)
{
// function declarations
matrix QRdecomp(matrix* A);
int FindZero(trimatrix* T);
double GetShift(trimatrix* T);

// get size
const int N = T->rows; assert(N==T->cols);

if (N==1)
{ return; }
else
{
int k = FindZero(T); // see if we can deflate

if (k==N) // can’t deflate
{
// Find shift to improve convergence
double mu = GetShift(T);

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

// Subtract shift from bigger matrix
for (int i=1; i<=N; i++)
{ mget(R,i,i) -= mu; }
