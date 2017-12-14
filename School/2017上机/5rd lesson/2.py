# Shangji Practice No 2
# Meng Yit Koh
# 517030990022

def greatestValue(x,y):
    # x is list y is index
    for i in range(len(x)):
        if y == i: continue
        elif x[y] >= x[i]:
            maximum = x[y]
        else:
            return greatestValue(x, y+1)
    return maximum

def lowestValue(x,y):
    # x is list y is index
    for i in range(len(x)):
        if y == i: continue
        elif x[y] <= x[i]:
            minimum = x[y]
        else:
            return lowestValue(x, y+1)
    return minimum

def main():
    listInput = [1,2,3,4,5,5]
    if len(listInput) == 1:
        min, max = listInput[0]
    elif len(listInput) == 2:
        if listInput[0] > listInput[1]:
            min, max = listInput[1], listInput[0]
    else:
        max, min = greatestValue(listInput, 0), lowestValue(listInput, 0)
    print 'Minimum:', min, 'Maximum:', max

main()
