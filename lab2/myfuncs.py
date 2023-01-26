import math
def exp(x, kmax=10000000):
    e = 2.7182818284590451
    x0 = int(round(x))
    z = x - x0
    expx0 = math.pow(e, x0)
    
    s = 0
    for k in range(kmax):
        s_old = s
        s = s_old + math.pow(z,k) / math.factorial(k)
        
        if abs(s - s_old) < 1e-16:
            break
    return expx0 * s
def ln(x, kmax=10000000):
    s = 1.0
    for k in range(kmax):
        s_old = s
        s = s_old - 1 + x * exp(-s_old)
        if abs(s - s_old) < 1e-16:
            break
        
    return s
# import numpy
# nn = 4
# print(exp(nn))
# print(exp(nn) - numpy.exp(nn))
# nn = 1000
# print(ln(nn) - numpy.log(nn))
