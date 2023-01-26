"""
My factorial function
"""

def factorial(n):
    s = 1
    for i in range(1,n):
        s = s * (i + 1)
    return s

