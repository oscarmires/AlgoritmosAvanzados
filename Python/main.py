# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.
from random import random
import matplotlib.pyplot as plt
import numpy as np


def integrate(f, n):
    k = 0
    for i in range(n):
        x = random()
        y = random() * f(1)

        if y <= f(x):
            k += 1
            plt.plot(x, y, c='r')
        else:
            plt.plot(x, y, c='b')

    plt.show()

    return k / n * f(1)


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    f = lambda x: (-x) ** 3 + 6 * x ** 2 - x + 17
    area = integrate(f, 1000)
    print(area)
