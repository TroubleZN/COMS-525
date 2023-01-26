"""

"""

def sqrt_newton(x, kmax):
    """
    Compute the square root of a number using Newton's method
    Input: x: real number
           kmax: integer, the maximum number of iterations, default is 100
    Output: return sqrt of x
    """

    x = 1.0*x

    if x==0.0:
        return 0.0
    elif x<0.0:
        print("** ERROR: input x must be non-negative **")
        return -1.0

    s = initial_guess
    for k in 
