import numpy as np


def add(array_1, array_2):
    return array_1 + array_2


array_1 = np.loadtxt("matriz2.txt", dtype=float, delimiter=' ')
array_2 = np.loadtxt("matriz3.txt", dtype=float, delimiter=' ')

result = add(array_1, array_2)

np.savetxt("result.txt", result, fmt='%.2f', delimiter=' ', newline='\n')
