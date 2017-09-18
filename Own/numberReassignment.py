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

numbersReassignment()
print 'Have a good day'