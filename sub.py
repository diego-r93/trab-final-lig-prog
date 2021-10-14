#!/usr/bin/env python3

import sys
import numpy as np
from operations import sub

array_1 = np.loadtxt(sys.argv[1], dtype=float, delimiter=' ')
array_2 = np.loadtxt(sys.argv[2], dtype=float, delimiter=' ')

result = sub(array_1, array_2)

np.savetxt("result.txt", result, fmt='%.2f', delimiter=' ', newline='\n')
