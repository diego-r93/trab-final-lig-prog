import numpy as np


def add(array_1, array_2):
    return array_1 + array_2


def sub(array_1, array_2):
    return array_1 - array_2


def mult(array_1, array_2):
    return array_1.dot(array_2)


def inv(array):
    return np.linalg.inv(array)


def det(array):
    np.linalg.det(array)


def transp(array):
    return array.T


if __name__ == '__main__':
    try:
        array_1 = np.loadtxt("matriz1.txt", dtype=float, delimiter=' ')
        array_2 = np.loadtxt("matriz2.txt", dtype=float, delimiter=' ')
        array_3 = np.loadtxt("matriz3.txt", dtype=float, delimiter=' ')
        array_4 = np.loadtxt("matriz4.txt", dtype=float, delimiter=' ')
    except:
        print("Error opening files.")

    # Soma de 2 com 3
    print("Soma de 2 com 3:")
    print(add(array_2, array_3))
    print()

    # Subtração de 2 com 3
    print("Subtração de 2 com 3")
    print(sub(array_2, array_3))
    print()

    # Multiplicação de 1 por 2
    z = array_1.dot(array_2)
    print("Multiplicação de 1 por 2")
    print(mult(array_1, array_2))
    print()

    # Inversa da Matriz 4
    print("Inversa da Matriz 4")
    print(inv(array_4))
    print()

    # Determinante da Matriz 4
    z = np.linalg.det(array_4)
    print("Determinante da Matriz 4")
    print(det(array_4))
    print()

    # Transposta de 2
    z = array_2.T
    print("Transposta de 2")
    print(transp(array_2))
    print()
