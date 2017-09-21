#Module for Guessing Square Root Project
#Created by MyKoh
#2017-09-23
import math

x = input('Please insert a number to find its square root:')

def squareRootGuessing():
    guess = x / 2
    for i in range(x ** 2):
        guess = (guess + (x / guess)) / 2
    print guess

squareRootGuessing()

#To know real root value for comparison:
realRoot = math.sqrt(x)
print realRoot