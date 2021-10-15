#!/usr/bin/env python3

import sys
import numpy as np
from operations import inv

array = np.loadtxt(sys.argv[1], dtype=float, delimiter=' ')

result = inv(array)

np.savetxt("result.txt", result, fmt='%.2f', delimiter=' ', newline='\n')
