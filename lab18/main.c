#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef _OPENMP
#   include <omp.h>
#endif


int main(int argc, char* argv[]) 
{
    void usage(const char* prog_name);
    void CompTrap(const double a,const double b,const int N,double* T);

    if (argc != 4) { usage(argv[0]); }
    const int thread_count = strtol(argv[1], NULL, 10);
    const int N = strtol(argv[2], NULL, 10);
    const int k = strtol(argv[3], NULL, 10);

    if (thread_count<1 || N<1 || k<1)
    { usage(argv[0]); }
    
    double* A[N][k];
    double* v[k];
    for (int j=0; j<k; j++)
    {   
        v[k] = rand() % 100000;
        for (int i=0; i<N; i++)
        {
            A[i][j] = rand() % 100000;
        }
    }
    
    double T = 0.0;

    const double time1 = omp_get_wtime();

#   pragma omp parallel num_threads(thread_count)
    CompTrap(a,b,N,&T);

    const double time2 = omp_get_wtime();

    double Iex = exp(1.0); double err = fabs(T-Iex);
    
    printf("\n N = %i, T = %23.15e, err = %12.5e,\n",N,T,err);
    printf(" time = %12.5e\n\n",time2-time1);

    return 0;
}

void usage(const char *prog_name)
{
    fprintf(stderr,"usage: %s <num_threads> <num_row> <num_col>\n", prog_name);
    fprintf(stderr,"    num_threads should be positive\n");
    fprintf(stderr,"    num_row should be positive\n");
    fprintf(stderr,"    num_col should be positive\n");
    exit(1);
}

void matrix_vector_product(const double a, const double b, const int N, double* T_global)
{
#   ifdef _OPENMP
    const int my_rank = omp_get_thread_num();
    const int thread_count = omp_get_num_threads();
#   else
    const int my_rank = 0;
    const int thread_count = 1;
#   endif

    double func(const double x);
    double h = (b-a)/((double)N);

    double local_N = N/thread_count;
    double local_a = a + my_rank*local_N*h;
    double local_b = local_a + local_N*h;

    double T_local = 0.5*(func(local_a)+func(local_b));
    double x_local = local_a;

    for (int i=1; i<local_N; i++)
    {
        x_local += h;
        T_local += func(x_local); 
    }

#   pragma omp critical
    *T_global += h*T_local; 
}

double func(const double x)
{
    return (1.0 + exp(x));
}

