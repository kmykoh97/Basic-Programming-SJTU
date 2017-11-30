# Shangji Practice No 1
# Meng Yit Koh
# 517030990022

from random import *

def main():
    n = 9999#input("Please insert number of throws:")
    squareSidesLength = 2#input("Please insert sides' length of square:")
    x = squareSidesLength * random() - squareSidesLength/2.0
    y = squareSidesLength * random() - squareSidesLength/2.0
    numberOfThrows = n * 1.0
    h = 0
    while numberOfThrows > 0:
        if x**2 + y**2 <= (squareSidesLength/2.0)**2:
            h += 1
        numberOfThrows -= 1
    piValue = 4.0 * h / n
    print "Pi estimated value is:", piValue

main()
