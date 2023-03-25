#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#ifdef _OPENMP
#   include <omp.h>
#endif


int main(int argc, char* argv[]) 
{
    void usage(const char* prog_name);
    double matrix_vector_product_norm(const int N, const int k);
    void comp_norm(const int N, double *w, double *norm);

    if (argc != 4) { usage(argv[0]); }
    const int thread_count = strtol(argv[1], NULL, 10);
    const int N = strtol(argv[2], NULL, 10);
    const int k = strtol(argv[3], NULL, 10);

    if (thread_count<1 || N<1 || k<1)
    { usage(argv[0]); }
    
    double norm = 0.0;
    
    const double time1 = omp_get_wtime();
#   pragma omp parallel num_threads(thread_count)
    {
        double norm_local = matrix_vector_product_norm(N, k);
#       pragma omp critical
        norm += norm_local;
    }    
    const double time2 = omp_get_wtime();
    double clock_time = time2 - time1;

    printf(" With %i threads, clock_time = %11.5e (sec), N = %i, k = %i, the 1-norm of w is %f\n", thread_count ,clock_time, N, k, norm);
    return 0;
}

void usage(const char *prog_name)
{
    fprintf(stderr,"usage: %s <num_threads> <num_row> <num_col>\n", prog_name);
    fprintf(stderr,"    num_threads should be positive\n");
    fprintf(stderr,"    num_row should be positive\n");
    fprintf(stderr,"    num_col should be positive\n");
    fprintf(stderr,"    num_threads should smaller than num_row\n");
    fprintf(stderr,"    mod(num_row, num_threads) != 0\n");
    exit(1);
}

double matrix_vector_product_norm(const int N, const int k)
{
#   ifdef _OPENMP
    const int my_rank = omp_get_thread_num();
    const int thread_count = omp_get_num_threads();
#   else
    const int my_rank = 0;
    const int thread_count = 1;
#   endif

    int local_N = N/thread_count;
    
    int i_start = my_rank*local_N + 1;
    int i_end = (my_rank+1)*local_N;

    double w_local[N];

    for (int i=i_start; i<=i_end; i++) 
    {   
        w_local[i-1] = 0.0;
        for (int j=1.0; j<=k; j++)
        {
            w_local[i-1] += 1.0/(i+j-1.0) / j;
        }

// #       pragma omp critical
//         *norm += fabs(w_i);
    }
    double norm_local = 0.0;
    for (int i=i_start; i<=i_end; i++) 
    {  
        norm_local += fabs(w_local[i-1]);
    }
    return norm_local;
}
