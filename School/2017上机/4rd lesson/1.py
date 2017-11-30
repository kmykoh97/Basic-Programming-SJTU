# Shangji Practice No 1
# Meng Yit Koh
# 517030990022

from random import *

def main():
    n = input("Please insert number of throws:")
    squareSidesLength = input("Please insert sides length of square:")
    radius = squareSidesLength / 2.0
    numberOfThrows, h = n * 1.0, 0
    while n > 0:# loop started until finish try
        x, y = ((radius + 1) * random()) - 1, ((radius + 1) * random()) - 1
        if (x**2 + y**2) <= (radius**2):
            h += 1
        n -= 1
    piValue = (4.0 * h) / numberOfThrows
    print "Pi estimated value is:", piValue

main()
