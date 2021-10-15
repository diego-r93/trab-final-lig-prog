#!/usr/bin/env python3

import sys
import matplotlib.pyplot as plt
import csv

x = []
y = []

try:
    with open(sys.argv[1], 'r') as csvfile:
        plots = csv.reader(csvfile, delimiter=',')
        for row in plots:

            x.append(int(row[0]))
            y.append(int(row[1]))

        plt.plot(x, y)
        plt.show()
except:
    print(f"Não foi possível encontrar o arquivo {sys.argv[1]}")
