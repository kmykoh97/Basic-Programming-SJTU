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

# fibonacciSequence()

# efficient codes
def fs(x):
    if x == 1 or x == 2:
        return 1
    else:
        return fs(x-1) + fs(x-2)

def main():
    nthFibonacci = input('Please insert the nth term of fibonacci number you want to find:')
    print "the %dth term is:" % (nthFibonacci), fs(nthFibonacci)
    print fsList(nthFibonacci)

def fsList(x):
    listA = []
    for i in range(1, x+1):
        if i == 1 or i == 2:
            listA.append(1)
        else: listA.append(fs(i))
    return listA

main()
