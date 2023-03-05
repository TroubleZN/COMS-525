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

    double lambda = 0;
    double lambda_old;
    int mstop = 0; 
    int k = 0;

    // const int rows = A->rows;
    const int size = v->size;

    matrix v_m;
    matrix v_m_prim;
    matrix lambda_t;
    vector lambda_m;
    vector w;
    double w_norm;

    while (mstop == 0)
    {   
        k += 1;
        lambda_old = lambda;
        w = matrix_vector_mult(A, v);
        w_norm = vector_norm(&w);
        for (int i=1; i<=size; i++)
        {
            vgetp(v, i) = vget(w, i) / w_norm;
        }

        v_m = vector_to_matrix(v);
        v_m_prim = matrix_trans(&v_m);
        lambda_t = matrix_mult(&v_m_prim, A);
        lambda_m = matrix_vector_mult(&lambda_t, v);
        lambda = vget(lambda_m, 1);

        if (fabs(lambda - lambda_old) < TOL || k == MaxIters)
        { mstop = 1; }
    }
    return lambda;
}

double shifted_inverse_power_iteration(double mu, vector *v, matrix *A, double TOL, int MaxIters)
{
    /*
    Shifted inverse power iteration for computing the closest eigenvalue to μ 
    Input:
        mu: 
        v: initial guess, vector
        A: the matrix, matrix
        TOL: tolerance for checking convergence (difference between succesive iterations), double
        MaxIters: Max number of iterations allowed
    Output:
        return the eigenvalue closest to μ 
    */

    double lambda = 0;
    double lambda_old;
    int mstop = 0; 
    int k = 0;

    // const int rows = A->rows;
    const int size = v->size;

    matrix v_m;
    matrix v_m_prim;
    matrix lambda_t;
    vector lambda_m;    
    vector w;
    double w_norm;
    matrix A_new;

    matrix muI = new_matrix(size, size);
    for (int i=1; i<=size; i++)
    { mget(muI, i, i) = mu; }

    while (mstop == 0)
    {   
        k += 1;
        lambda_old = lambda;
        
        A_new = matrix_sub(A, &muI);
        w = solve(&A_new, v);

        w_norm = vector_norm(&w);
        for (int i=1; i<=size; i++)
        {
            vgetp(v, i) = vget(w, i) / w_norm;
        }

        v_m = vector_to_matrix(v);
        v_m_prim = matrix_trans(&v_m);
        lambda_t = matrix_mult(&v_m_prim, A);
        lambda_m = matrix_vector_mult(&lambda_t, v);
        lambda = vget(lambda_m, 1);

        if (fabs(lambda - lambda_old) < TOL || k == MaxIters)
        { mstop = 1; }
    }
    return lambda;
}


double rayleigh_quotient_iteration(vector *v, matrix *A, double TOL, int MaxIters)
{
    /*
    Rayleigh Quotient Iteration for some eigenvalue of A after k iterations
    Input:
        v: initial guess, vector
        A: the matrix, matrix
        TOL: tolerance for checking convergence (difference between succesive iterations), double
        MaxIters: Max number of iterations allowed
    Output:
        return some eigenvalue of A
    */

    double lambda = 0;
    double lambda_old;
    int mstop = 0; 
    int k = 0;

    // const int rows = A->rows;
    const int size = v->size;
    
    matrix v_m;
    matrix v_m_prim;
    matrix lambda_t;
    vector lambda_m;    
    vector w;
    double w_norm;
    matrix A_new;
    matrix lambdaI = new_matrix(size, size);

    while (mstop == 0)
    {   
        k += 1;
        lambda_old = lambda;
        
        for (int i=1; i<=size; i++)
        { mget(lambdaI, i, i) = lambda; }

        A_new = matrix_sub(A, &lambdaI); 
        w = solve(&A_new, v);
        
        w_norm = vector_norm(&w);
        for (int i=1; i<=size; i++)
        {
            vgetp(v, i) = vget(w, i) / w_norm;
        }

        v_m = vector_to_matrix(v);
        v_m_prim = matrix_trans(&v_m);
        lambda_t = matrix_mult(&v_m_prim, A);
        lambda_m = matrix_vector_mult(&lambda_t, v);
        lambda = vget(lambda_m, 1);

        if (fabs(lambda - lambda_old) < TOL || k == MaxIters)
        { mstop = 1; }
    }
    return lambda;
}