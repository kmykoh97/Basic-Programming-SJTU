#Second Shangji Practice
#Meng Yit Koh
#517030990022

def main():
    userInput = input('Please insert a positive integer:')
    resultList = [userInput]
    condition = True
    while condition:
        if userInput % 2 == 0:
            userInput /= 2
            resultList.append(userInput)
        else:
            userInput = 3 * userInput + 1
            resultList.append(userInput)
            
        if userInput == 1:
            condition = False

    print 'Syracuse:', resultList

    input()

main()
