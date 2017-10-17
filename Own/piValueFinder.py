#A program to try to find pi
#Created by MyKoh
#2017-10-19

#Given formula:
#pi/4 = 1 - 1/3 + 1/5 - 1/7 +...
#pi/4 = (-1)**n/(2*n-1)

def pi():
    n = 1
    piDivideFour = 0
    while 1/(2*n-1) - 1/(2*(n+1)-1) > 0.00001:
        piDivideFour += (-1)**(n+1)/(2*n-1)
        n += 1

    print piDivideFour
    print piDivideFour * 4

pi()
