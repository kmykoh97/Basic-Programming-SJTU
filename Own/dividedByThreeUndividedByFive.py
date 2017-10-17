#Numbers that can be divided by 3 and cannot be divided by 5
#Created by MyKoh
#2017-10-18

def main():
    result = 0
    for i in range(1, 1001):
        if i % 3 == 0 and i % 5 != 0:
            result += i

    print 'The total is', result

main()
