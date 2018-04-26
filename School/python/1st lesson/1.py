#First Shangji Practice
#Meng Yit Koh
#517030990022

def main():
    result = 0
    for i in range(1, 1001):
        if i % 3 == 0 and i % 5 != 0:
            result += i

    print 'The total is', result
    input()

main()
