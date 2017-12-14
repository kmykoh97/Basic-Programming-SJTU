# Shangji Practice No 3
# Meng Yit Koh
# 517030990022

<<<<<<< HEAD
def main():
    global competitorsListA
    global competitorsListB
    global timeList
    timeList, competitorsListA, competitorsListB, a = [], [], [], 1
    n = input('Please insert number of competitors:')
    for i in range(n):
        timeList.append(input('Please tell me time needed by player %d:' %(i+1)))
    for i in range(n):
        competitorsListA.append(a)
        a += 1
    print determineFastest(n, timeList) - minimum(timeList)

def compareTime(x, y, timeList):
    # x is first competitor, y is second
    totalTime = timeList[x-1] + timeList[y-1]
    if timeList[x-1] > timeList[y-1]:
        competitorsListB.append(competitorsListA[x-1])
    else:
        competitorsListB.append(competitorsListA[y-1])
        # return diving(y, x, timeList)
    # competitorsListA.sort()
    return totalTime

def totalTime(n, x, timeList):
    totalTime = 0
    for j in range(n):
        if x == j+1: continue
        totalTime += diving(x, j+1, timeList)
    return totalTime

def determineFastest(n, timeList):
    i, q = 1, []
    while i <= n:
        q.append(totalTime(n, i, timeList))
        i += 1
    indexOfLeastTime = q.index(minimum(q))
    return totalTime(n, indexOfLeastTime+1, timeList)

def lowestValue(x,y):
    # x is list y is index
    for i in range(len(x)):
        if y == i: continue
        elif x[y] <= x[i]:
            minimum = x[y]
        else: return lowestValue(x, y+1)
    return minimum

def minimum(listInput):
    if len(listInput) == 1:
        min= listInput[0]
    elif len(listInput) == 2:
        if listInput[0] > listInput[1]: min = listInput[1]
    else:
        min = lowestValue(listInput, 0)
    return min
=======
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
>>>>>>> revision2

main()
