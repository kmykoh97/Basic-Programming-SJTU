#Triangle Project
#Created by MyKoh
#2017-09-26

sides = input('Please enter the sides length saparated by comma:')
x = list(sides)
p = (x[0] + x[1] + x[2]) / 2

def tri():
    if x[0] + x[1] < x[2]:
        print 'Invalid(Cannot form triangle)'
    if x[0] + x[2] < x[1]:
        print 'Invalid(Cannot form triangle)'
    if x[2] + x[1] < x[0]:
        print 'Invalid(Cannot form triangle)'
    else:
        print 'The perimeter is', x[2] + x[1] + x[0]
        print 'The area is', (p*(p-x[0])*(p-x[1])*(p-x[2])) ** 0.5

tri()