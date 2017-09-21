#Factorial Project
#Created by MyKoh
#2017-09-20

print 'This a a program to find factorial'
def factorial():
    n = input('Please insert a whole number:')
    x = 1L #Use a long integer here
    for i in range(2, n+1):
        x *= i
    print 'Factorial of', n, 'is', x

factorial()
print 'Have a good day'