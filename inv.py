#!/usr/bin/env python3

import sys
import numpy as np
from operations import inv

try:
    array = np.loadtxt(sys.argv[1], dtype=float, delimiter=' ')

    result = inv(array)

    np.savetxt("result.txt", result, fmt='%.2f', delimiter=' ', newline='\n')

except:
    print(f"Não foi possível encontrar o arquivo {sys.argv[1]}")
