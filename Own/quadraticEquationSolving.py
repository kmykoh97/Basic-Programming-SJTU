#Project to solve quadratic equation
#Created by MyKoh
#2017-09-19

#requesting user input:
print 'Hello, this is a program to solve quadratic equation'
print 'ax^2 + bx + c = 0'

def quadraticEquation():
    while True:
        #requesting user input:
        #a = input('Please insert your a')
        #b = input('Please insert your b')
        #c = input('Please insert your c')
        #a, b, c = input("Please insert (a, b, c):")
        a, b, c = input("Please enter the coefficients (a, b, c): ")

        x = b ** 2 - 4 * a * c

        if x < 0:
            print 'It has no real roots'
        elif x == 0:
            print 'Your equation has 2 same roots which are:', (-b + (x//2))/2*a
        else:
            print 'The solutions are:', ((-b + (x//2))/2*a), 'and', (-b - (x//2))/2*a

        NewCalculation = raw_input('Thank you for using me, do you want to start a new calculation?(y or n)')
        if NewCalculation == 'y':
            print 'OK'
        elif NewCalculation == 'n':
            break
        else:
            #I can make one more loop here. Try again next time
            print "I don't understand you. I will assume you want to terminate program."
            break


quadraticEquation()
print 'Have a good day'