#Program to reverse numbers entered in list
##Created by MyKoh
#2017-10-20

def main():
    oldList = []
    newList = []
    numberInList = input('Please enter the amount of numbers u wish to insert:')
    a = numberInList - 1
    for i in range(numberInList):
        oldList.append(input('Please enter number:'))
    print oldList
    while a >= 0:
        newList.append(oldList[a])
        a -= 1
    print newList
    
main()
