#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) 
{
    void usage(const char* prog_name);
    double CompTrap(const double a,const double b,const int N);

    if (argc != 2) { usage(argv[0]); }
    const int N = strtol(argv[1], NULL, 10);
    if (N<1) { usage(argv[0]); }

    const double a = 0.0; const double b = 1.0;
    double T = CompTrap(a,b,N);
    const double Iex = exp(1.0);
    const double err = fabs(T-Iex);

    printf("\n N = %i, T = %23.15e, err = %12.5e\n\n",N,T,err);

    return 0;
}

void usage(const char *prog_name) 
{
    fprintf(stderr, "usage: %s <num_intervals>\n", prog_name);
    fprintf(stderr, " num_intervals should be positive\n");
    exit(1);
}

double CompTrap(const double a, const double b, const int N) 
{
    double func(const double x);
    double h = (b-a)/((double)N);
    double T = 0.5*(func(a)+func(b));
    double x = a;

    for (int i=1; i<N; i++)
    {
        x += h;
        T += func(x);
    }

    return h*T;
}

double func(const double x) 
{
    return (1.0 + exp(x)); 
}