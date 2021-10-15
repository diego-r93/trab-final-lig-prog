#!/usr/bin/env python3

import sys
import numpy as np
from operations import det

try:
    array = np.loadtxt(sys.argv[1], dtype=float, delimiter=' ')

    result = det(array)

    file = open("result.txt", "w")
    file.write(str(result))
    file.close()

except:
    print(f"Não foi possível encontrar o arquivo {sys.argv[1]}")
