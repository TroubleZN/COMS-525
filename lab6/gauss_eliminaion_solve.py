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
    
    # b = np.matrix(b)
    # if b.shape[0] == 1:
    #     b = b.T

    # main body
    m_combined = np.column_stack((A, b))

    print('Gaussian Elimination === ') 
    for i in range(n):
        col_i = m_combined[:,i]
        print('Gauss elemination along col=',i,':')
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
        print(m_combined) 

    x = m_combined[:,-1]
    print('The solution is: \n', x)
    return x


# The test function 
def test():
    A = np.array([[-2, 0, 1], [-1, 7, 1], [5, -1, 1]], dtype=float)
    b = np.matrix([-4, -50, -26], dtype=float).T

    from numpy.linalg import solve, norm

    x_my = mysolve(A,b)

    print('The result from numpy solve is:')
    x_np = solve(A,b)
    print(x_np)
    print('Error compuared with numpy solve is ', norm(x_my-x_np))


# Polynomial interpolation application
def Poly_interp():
    #solve the problem
    x = np.array([-0.1, -0.02, 0.02, 0.1])
    # x = np.array([0, 1, 2, 4])
    n = x.size

    A = np.ones((n, n))
    A[:,0] = x**3
    A[:,1] = x**2
    A[:,2] = x

    f = np.cos(x)
    res = mysolve(A, f)

    from numpy.linalg import solve, norm
    print('The result from numpy solve is:')
    x_np = solve(A,f)
    print(x_np)
    print('Error compuared with numpy solve is ', norm(res-x_np))


    # plots
    import matplotlib.pyplot as plt
    xgrid = np.linspace(x[0], x[-1], 101)
    f = np.cos(xgrid)
    p = np.zeros(101)
    for k in range(n):
        p = p + xgrid**(n-k-1)*res[k]

    plt.plot(xgrid,f,'r',xgrid,p,'o')
    plt.show()


# run
if __name__ == '__main__':
    Poly_interp()

    print('\nThe results from lab assignment 5:\n')
    test()

