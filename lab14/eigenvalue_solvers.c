#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

double power_iteration(vector *v, matrix *A, double TOL, int MaxIters)
{
    /*
    Power iteration for computing largest eigenvalue
    Input:
        v: initial guess, vector
        A: the matrix, matrix
        TOL: tolerance for checking convergence (difference between succesive iterations), double
        MaxIters: Max number of iterations allowed
    Output:
        return largest eigenvalue in magnitude
    */

    double lambda;
    int mstop = 0; 
    int k = 0;

    const int rows = A->rows;
    const int size = v->size;
    double v_norm = vector_norm(&v);

    for (int i=1; i<=size; i++)
    {
        vgetp(v, i) = vegtp(v, i) / v_norm;
    }

    matrix v_m = vector_to_matrix(&v);
    matrix v_m_prim = matrix_trans(&v_m);
    matrix lambda_t = matrix_mult(&v_m_prim, &A);
    vector lambda_m = matrix_vector_mult(&lambda_t, &v);
    lambda = vget(lambda_m, 1);



    while (mstop == 0)
    {
        k += 1;

    }
    

}

double shifted_inverse_power_iteration(vector *v, matrix *A, double TOL, int MaxIters)
{
    /*
    Shifted inverse power_iteration for computing largest eigenvalue
    Input:
        v: initial guess, vector
        A: the matrix, matrix
        TOL: tolerance for checking convergence (difference between succesive iterations), double
        MaxIters: Max number of iterations allowed
    Output:
        return largest eigenvalue in magnitude
    */


}