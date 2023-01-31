"""
My Gauss elimination solver
"""

# packages
import numpy as np

def mysolve(A,b):
    """
    This is a linear solver based on Gauss elimination

    Model: 
        Ax = b
    Inupt:
        A: Float numpy matrix (dims n x n)
        b: Float numpy matrix (dims n x 1)
    Output:
        x: Float numpy matrix (dims n x 1)
    """

    # input dims check
    m, n = A.shape
    if m != n:
        return -1
        print("The matrix A should be square.")
    if n != b.shape[0]:
        return -1
        print("The dims of the A and b are not consistent.")

    # main body
    m_combined = np.hstack((A, b))

    for i in range(n):
        col_i = A[:,i]
        for j in range(i,n):
            if col_i[j] != 0:
                m_i = np.copy(m_combined[i,:])
                m_combined[i,:] = m_combined[j,:]
                m_combined[j,:] = m_i

                m_combined[i,:] = m_combined[i,:] / m_combined[i,i] 
                for k in range(n):
                    if k != i:
                        m_combined[k,:] -= m_combined[i,:] * m_combined[k,i]
                break

    x = m_combined[:,-1]
    return x




A = np.array([[-2, 0, 1], [-1, 7, 1], [5, -1, 1]], dtype=float)
b = np.matrix([-4, -50, -26], dtype=float).T

from numpy.linalg import solve
solve(A,b)

