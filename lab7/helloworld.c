#include <stdio.h>

int factorial(int n)
{
    // Declare variables
    // const int n = -5;
    int nfactorial = 1;
    int i;

    // Check n
    if (n<0)
    {
        printf("n = %i is a negative value, which is invalid! \n", n);
        printf("\n");
    }
    else
    {
        // for loop
        for (i=1; i<=n; i++)
        {
            nfactorial = nfactorial*i;
        }

        // Print
        printf("nfactorial = %i when n = %i\n", nfactorial, n);
        printf("\n");
    }

    // Return 0 to signify successful completion
    return 0;
}

int minimum()
{
    // Declare some variables
    double x = -1.43;
    double y = 4.5014;
    double min;

    // Check which one is smaller
    if (x<y)
    {
        min = x;
    }
    else
    {
        min = y;
    }

    // Print
    printf("minimum of x and y = %.3f\n", min);
    printf("\n");

    // Return 0 to signify successful completion
    return 0;
}

int main()
{
    // Print a message to the screen
    printf("\n");
    printf("Hello World! My name is Cy.\n");
    printf("\n");

    // Declare the pi variable
    float pi;
    pi = 3.1415926;

    // Print the value of pi in different format
    printf("This is the value of pi: %f\n", pi);
    printf("This is the value of pi: %.3f\n", pi);
    printf("This is the value of pi: %.3e\n", pi);
    printf("This is the value of 10*pi: %.3e\n", 10*pi);
    printf("\n");

    // Declare some variables
    double x = 3.0;
    double y = 0.1;
    double z;

    // Add x to y 
    z = x + y;

    // Print
    printf("z = %010.2f\n", z);
    printf("\n");

    // Minimum function application
    minimum();

    // Factorial function application
    factorial(8);
    factorial(-3);

    // Return 0 to signify successful completion
    return 0;
}
