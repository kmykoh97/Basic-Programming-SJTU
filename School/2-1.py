# Shangji Exercise No 1
# Meng Yit Koh 517030990022

def main():
    n = input("Please insert number of lamps:")
    k = input('Please insert number of people:')
    nList = []
    #Conditions:
    if n >= 1000 or k >= n:
        print 'invalid'
    #Starting Of Algorithm:
    else:
        #Light up all bulbs:
        for i in range(1, n+1):
            nList.append(i)
        #Dim and light bulbs accordingly:
        for j in range(2, k+1):
            for l in range(j, n+1, j):
                if l in nList:
                    nList.remove(l)
                else:
                    nList.append(l)
                nList.sort()

    print 'Lighted lamps are:', nList

main()

