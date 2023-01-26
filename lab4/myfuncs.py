"""
My sqrt function using Newton's method
"""

def factorial(n):
    """
    My factorial function
    """
    s = 1
    for i in range(1,n):
        s = s * (i + 1)
    return s


def exp(x, kmax=100):
    """
    My exponential function
    """
    e = 2.7182818284590451
    x0 = int(round(x))
    z = x - x0
    expx0 = e ** x0
    
    s = 0
    for k in range(kmax):
        s_old = s
        s = s_old + z**k / factorial(k)
        
        if abs(s - s_old) < 1e-16:
            break
    return expx0 * s

def ln(x, kmax=100):
    """
    My natural logarithm function
    """
    s = 1.0
    for k in range(kmax):
        s_old = s
        s = s_old - 1 + x * exp(-s_old)
        if abs(s - s_old) < 1e-16:
            break
        
    return s


def sqrt_newton(x,kmax=100,initial_guess=1,tol=1e-14,printhow=0):
    """
    Compute the square root of a number using Newton's method
    Input: x: real number
           kmax: integer, the maximum number of iterations, default is 100
           initial_guess: real number, initial guess for iteration, default is 1
           tol: real number, tolerance to terminate the iteration, default is 1e-14
           printhow: integer, switch for whether to print the procedure
    Output: return sqrt of x
    """

    x = 1.0*x

    if x==0.0:
        return 0.0
    elif x<0.0:
        print("** ERROR: input x must be non-negative **")
        return -1.0

    s = initial_guess
    for k in range(kmax):
        if printhow != 0:
            print("Before iteration %2d, s = %20.15f" % (k,s))
        s_old = s
        s = s - (s ** 2 - x) / (2 * x)
        if abs(s - s_old) < tol:
            if printhow != 0:
                print("After %2d iterations, s = %20.15f" % (k+1,s))
            break

    return s



def test_my():
    import numpy as np
    print(sqrt_newton(3.7))
    print(sqrt_newton(3.7) - np.sqrt(3.7))

    sqrt_newton(3.7, kmax=3, printhow=1)

    sqrt_newton(3.7, initial_guess=2, printhow=1)

    print(exp(3.7))
    print(exp(3.7) - np.exp(3.7))

    print(ln(3.7))
    print(ln(3.7) - np.log(3.7))

    print(factorial(5))
    print(factorial(6))
    print(factorial(7))

test_my()