#Third Shangji Practice
#Meng Yit Koh
#517030990022

def main():
    originalValue = input('Please insert price:')
    change = 100.0 - originalValue
    a, b, c, d, e, f = 0, 0, 0, 0, 0, 0
    if originalValue > 100 or originalValue < 0:
        print 'Invalid amount!'
    elif originalValue % 1 != 0:
        print 'Please insert whole number!'
    else:
        while change - 50 >= 0:
            change -= 50
            a += 1
        while change - 20 >= 0:
            change -= 20
            b += 1
        while change - 10 >= 0:
            change -= 10
            c += 1
        while change - 5 >= 0:
            change -= 5
            d += 1
        while change - 2 >= 0:
            change -= 2
            e += 1
        while change - 1 >= 0:
            change -= 1
            f += 1

        print 'Returns are', a, 'x 50,', b, 'x 20,', c, 'x 10,', d, 'x 5,', e, 'x 2,', f, 'x 1,'

    input()
    
main()
