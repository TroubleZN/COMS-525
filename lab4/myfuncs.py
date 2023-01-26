"""
My sqrt function
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

    

