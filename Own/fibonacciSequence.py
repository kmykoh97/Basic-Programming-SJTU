#A Fibonacci sequence is a sequence of numbers where each successive number is the sum of the previous two. The classic Fibonacci sequence begins: 1, 1, 2, 3, 5, 8, 13, . Write a program that computes the nth Fibonacci number where n is a value input by the user.
#Fibonacci sequence program
##Created by MyKoh
#2017-09-21

def fibonacciSequence():
    x = input('Please enter any whole number greater than 0:')
    value = [1, 1]
    for i in range(x-2):
        value.append(value[i] + value[i+1])
    print value
    print 'The',x , 'th fibonacci number is', value[x-1]

fibonacciSequence()