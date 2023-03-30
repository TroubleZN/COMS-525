#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "matrix.h"
#include <time.h>
#ifdef _OPENMP
#   include <omp.h>
#endif


int main(int argc, char* argv[]) 
{   
    srand( time(NULL) ); 
    void usage(const char* prog_name);
    void normalize_vector_fine(const int N, vector* v, double *norm);
    void normalize_vector_coarse(const int N, vector* v, double *norm);
    void comp_norm(const int N, double *w, double *norm);

    if (argc != 3) { usage(argv[0]); }
    const int thread_count = strtol(argv[1], NULL, 10);
    const int N = strtol(argv[2], NULL, 10);

    if (thread_count<1 || N<1 || N % thread_count != 0)
    { usage(argv[0]); }
    

    // initialize the vectors x and x2
    vector x = new_vector(N);
    for (int i=1; i<=N; i++)
    { vget(x,i) = 1; }
    // { vget(x,i) = (rand() % 10); }

    vector x2 = new_vector(N);
    for (int i=1; i<=N; i++)
    { vget(x2,i) = vget(x,i); }
    // print_vector(&x);

    // fine grain paralell
    double norm = 0.0;
    const double time1_1 = omp_get_wtime(); 

# pragma omp parallel num_threads(thread_count)
    {
#       pragma omp for reduction(+:norm) 
        for (int i=1; i<=N; i++)
        { norm += pow(vget(x,i),2); }

#       pragma omp single
        norm = sqrtf(norm);
#       pragma omp barrier

#       pragma omp for 
        for (int i=1; i<=N; i++)
        { vget(x,i) = vget(x,i) / norm; }
    }
    

    const double time1_2 = omp_get_wtime();
    double clock_time = time1_2 - time1_1;
    // print_vector(&x);


    // coarse grain paralell
    double norm2 = 0.0;
    const double time2_1 = omp_get_wtime();
#   pragma omp parallel num_threads(thread_count)
    {
        normalize_vector_coarse(N, &x2, &norm2);
    }
    const double time2_2 = omp_get_wtime();
    double clock_time2 = time2_2 - time2_1;
    // print_vector(&x2);
    

    double err = 0.0;
    for (int i=1; i<=N; i++)
    {
        err += fabs(vget(x,i)- vget(x2,i));
    }

    printf("                                Input N = %i\n", N);
    printf("                   norm frin fine grain = %f\n", norm);
    printf("                 norm frin coarse grain = %f\n", norm2);
    printf(" difference (Fine grain)-(Coarse grain) = %f\n", err);
    printf("                    Time for fine grain = %11.5e (sec)\n", clock_time);
    printf("                  Time for coarse grain = %11.5e (sec)\n", clock_time2);
    printf("                  Number of Threads Run = %i\n", thread_count);
    return 0;
}


void usage(const char *prog_name)
{
    fprintf(stderr,"usage: %s <num_threads> <num_row> <num_col>\n", prog_name);
    fprintf(stderr,"    num_threads should be positive\n");
    fprintf(stderr,"    N should be positive\n");
    fprintf(stderr,"    mod(N, num_threads) != 0\n");
    exit(1);
}


void normalize_vector_coarse(const int N, vector* v, double *norm)
{
#   ifdef _OPENMP
    const int my_rank = omp_get_thread_num();
    const int thread_count = omp_get_num_threads();
#   else
    const int my_rank = 0;
    const int thread_count = 1;
#   endif

    const int local_N = N/thread_count;
    
    const int i_start = my_rank*local_N + 1;
    const int i_end = (my_rank+1)*local_N;

    double norm_local = 0.0;

    for (int i=i_start; i<=i_end; i++) 
    {   
        norm_local += pow(vgetp(v, i),2);
    }

#   pragma omp critical
    *norm += norm_local;
#   pragma omp barrier

#   pragma omp single
    *norm = sqrtf(*norm); 
#   pragma omp barrier

    for (int i=i_start; i<=i_end; i++)
    { vgetp(v, i) = vgetp(v, i) / *norm; }
}
