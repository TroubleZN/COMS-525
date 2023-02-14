#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    const int Nmax = 5;
    int N;

    // read-in polynomial degree
    printf("\n Input polynomial degree (0-%i): ", Nmax);
    scanf("%i", &N);
    if (N<0 || N>Nmax)
    {
        printf(" Invalid value N = %i.\n", N);
        printf(" N must satisfy: 0 <= N <= %i\n\n", Nmax);
        exit(1);
    }
    printf("\n");

    // read-in coefficients
    double b[Nmax+1];
    for (int i = 0; i < N; i++)
    {
        printf(" Set b[%i]: ", i);
        scanf("%lf", &b[i]);
    }
    printf("\n");

    // set x-coordinates
    const int NumPts = 21;
    double x[NumPts];
    for (int i = 0; i < NumP; i++)
    {
        x[i] = -1.0 + i*(2.0/(1.0*(NumPts-1)));
    }

    // Calculate polynomial at x-coordinates
    double y[NumPts];
    void SamplePoly(const int N,
                    const int NumPts,
                    const double b[],
                    const double x[],
                    double y[]);
    SamplePoly(N, NumPtsm, b, x, y);
    
    
    

}