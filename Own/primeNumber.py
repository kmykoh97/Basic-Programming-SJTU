#Prime number
#Created by MyKoh
#2017-10-17

#Input: An integer, n
#Output: Sum of all prime numbers from 1 to n

def main():
    n = input('Please insert an integer: ')
    primeList = [2]
    for i in range(3, n+1):
        primeTF = True
        for j in range(2, i):
            if i%j == 0:
                primeTF = False
        if primeTF:
            primeList.append(i)

    print primeList

    result = 0
    for k in primeList:
        result += k

    print 'The total value is', result

main()