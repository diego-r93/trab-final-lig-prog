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
    return np.linalg.det(array)


def transp(array):
    return array.T
