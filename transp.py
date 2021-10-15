#!/usr/bin/env python3

import sys
import numpy as np
from operations import transp

array = np.loadtxt(sys.argv[1], dtype=float, delimiter=' ')

result = transp(array)

np.savetxt("result.txt", result, fmt='%.2f', delimiter=' ', newline='\n')
