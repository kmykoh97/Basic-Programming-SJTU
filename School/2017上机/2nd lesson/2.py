# Shangji Exercise No 2
# Meng Yit Koh 517030990022

def main():
    n = input('Enter a number:')
    base = input('Enter a number as base:')
    if 2 <= base <= 8:
        print 'The converted numbers in given base is:', ''.join(str(j) for j in printInt(n, base))#join the list as single string from printInt()
    else:
        print 'Invalid'

def printInt(x, y):
    l = []
    newL = []
    while x > 0:
        l.append(x%y)
        x = x / y
    return l[::-1]#Reverse the list

main()

