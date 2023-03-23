#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char* argv[]) 
{   
    srand(time(NULL));
    void usage(const char* prog_name);

    void usage(const char* prog_name);
    void CompTrap(const double a,const double b,const int N,double* T);

    if (argc != 4) { usage(argv[0]); }
    const int thread_count = strtol(argv[1], NULL, 10);
    const int N = strtol(argv[2], NULL, 10);
    const int k = strtol(argv[3], NULL, 10);

    if (thread_count<1 || N<1 || k<1)
    { usage(argv[0]); }
    
    double A[N][k];
    double v[k];
    for (int j=0; j<k; j++)
    {   
        *v[k] = rand() % 100000;
        for (int i=0; i<N; i++)
        {
            *A[i][j] = rand() % 100000;
        }
    }
    printf("%f", *v[0]);
}

void usage(const char *prog_name)
{
    fprintf(stderr,"usage: %s <num_threads> <num_row> <num_col>\n", prog_name);
    fprintf(stderr,"    num_threads should be positive\n");
    fprintf(stderr,"    num_row should be positive\n");
    fprintf(stderr,"    num_col should be positive\n");
    exit(1);
}