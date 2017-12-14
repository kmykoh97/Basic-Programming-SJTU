# Shangji Practice No 3
# Meng Yit Koh
# 517030990022

# A is starting point, B is ending point

def main():
    global A
    global B
    global timeList
    timeList, A, B = [], [], []
    n = input('Please insert number of competitors:')
    for i in range(n):
        timeList.append(input('Please tell me time needed by player %d:' %(i+1)))
    A = 1 * timeList
    totalTime = 0
    while len(A) > 2:
        totalTime += swimRight() + swimLeft()
    totalTime += swimRight()
    print 'Total time for all to cross is', totalTime

# function to ammend list of A and list of B then return the time taken from timeList
# going from initial postion to final point(2 persons)
def swimRight():
    A.sort()
    if len(B) == 0 or len(B) % 2 == 0:
        print 'Player', timeList.index(A[0])+1, 'and', 'Player', timeList.index(A[1])+1, 'go'
        B.append(A.pop(0))
        B.append(A.pop(0))
    else:
        A.reverse()
        print 'Player', timeList.index(A[0])+1, 'and', 'Player', timeList.index(A[1])+1, 'go'
        B.append(A.pop(0))
        B.append(A.pop(0))
    B.reverse()
    return B[0]

# function to ammend list of B and list of A then return the time taken from timeList
# going back from final position to initioal point(1 person)
def swimLeft():
    B.sort()
    print 'Player', timeList.index(B[0])+1, 'return'
    A.append(B.pop(0))
    A.reverse()
    return A[0]

main()
