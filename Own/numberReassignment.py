#Number Reasignment Project
#Created by MyKoh
#2017-09-18

#Telling purpose and requesting user's input
print 'Hello, this is a number reassignment in assending order program'
userInput = input('Please give numbers separated by comma')
x = list(userInput)
print 'Your given numbers are', x

#Create functin by loop
def numbersReassignment():
    initialCount = 0
    finalCount = len(x)
    while initialCount < finalCount ** 2:
        for i in range(len(x)-1):
            if x[i] > x[i+1]:
                x[i], x[i+1] = x[i+1], x[i]
            else:
                initialCount += 1
                
    print 'After sorting, the assending arrangement is:', x

#numbersReassignment()
print 'Have a good day'

#Below are more efficient codes to do the exact same thing
def efficientNumbersReassignment():
    for i in range(len(x)-1):
        for j in range(len(x)-1-i):
            if x[j] > x[j+1]:
                x[j], x[j+1] = x[j+1], x[j]

    print 'After sorting, the assending arrangement is:', x

def efficientNumbersReassignment2():
    for i in range(len(x)):
        for j in range(i + 1, len(x)):
            if x[i] > x[j]:
                x[i], x[j] = x[j], x[i]
    print x

