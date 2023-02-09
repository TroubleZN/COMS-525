#include<stdio.h>
#include<math.h>

int main()
{
    int factorial(int n);
    double exp(double x);

    double x[5];
    double a;
    double res;
    printf("Please provide the five numbers you want:\n");
    for (int i=0; i<5; i++)
    {   
        printf("%i: ", i);
        scanf("%lf", &a);
        x[i] = a;
    }


    FILE* outfile = fopen("out1.data","w");
    printf("\tx\texp(x)\n");
    for (int i=0; i<5; i++)
    {
        res = exp(x[i]);
        printf("\t%lf\t%lf\n", x[i], res);
        fprintf(outfile,"%23.16e\t%23.16e\n", x[i], res);
    }

    fclose(outfile);

    return 0;
}

// Exponential function based on Taylor expansions
double exp(double x)
{
    int factorial(int n);

    const double e = 2.718281828459;
    int kmax = 100;
    int x0 = round(x);
    double z = x - x0;
    double expx0 = pow(e, x0);

    double s = 0;
    double s_old;
    for (int k=0; k<kmax; k++)
    {
        s_old = s;
        s = s_old + pow(z, k) / factorial(k);

        if (fabs(s - s_old) < 1e-16)
        {
            break;
        }
    }
    return expx0*s;
}

// recursive factorial function
int factorial(int n)
{
    if (n <= 1)
    {   
        return 1;
    }
    else
    {   
        return n*factorial(n-1);
    }
}