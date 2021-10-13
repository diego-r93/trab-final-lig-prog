import numpy as np

try:
    array_1 = np.loadtxt("matriz1.txt", dtype=float, delimiter=' ')
    array_2 = np.loadtxt("matriz2.txt", dtype=float, delimiter=' ')
    array_3 = np.loadtxt("matriz3.txt", dtype=float, delimiter=' ')
    array_4 = np.loadtxt("matriz4.txt", dtype=float, delimiter=' ')
finally:
    array_1.close()
    array_2.close()
    array_2.close()
    array_2.close()


class Matriz:
    def add(array_1, array_2):
        return array_1 + array_2

    def sub(array_1, array_2):
        return array_1 - array_2

    def mult(array_1, array_2):
        return array_1.dot(array_2)


if __name__ == '__main__':
    # Soma de 2 com 3
    print("Soma de 2 com 3:")
    print(array_2 + array_3)
    print()

    # Subtração de 2 com 3
    print("Subtração de 2 com 3")
    print(array_2 - array_3)
    print()

    # Multiplicação de 1 por 2
    z = array_1.dot(array_2)
    print("Multiplicação de 1 por 2")
    print(z)
    print()

    # Inversa da Matriz 4
    z = np.linalg.inv(array_4)
    print("Inversa da Matriz 4")
    print(z)
    print()

    # Determinante da Matriz 4
    z = np.linalg.det(array_4)
    print("Determinante da Matriz 4")
    print(z)
    print()

    # Transposta de 2
    z = array_2.T
    print("Transposta de 2")
    print(z)
    print()
