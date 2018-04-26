# Shangji Practice No 2
# Meng Yit Koh
# 517030990022

import random

# Determine first dice value:
def firstDice():
    first = random.randint(1,6)
    return first

# Determine second dice value:
def secondDice():
    second = random.randint(1,6)
    return second

def winOrLose():
    totalPoints1 = firstDice() + secondDice() # This is p
    if totalPoints1 == 2 or totalPoints1 == 3 or totalPoints1 == 12:
        return False
    elif totalPoints1 == 7 or totalPoints1 == 11:
        return True
    else:
        while True:
            totalPoints2 = firstDice() + secondDice() # Rethrow dices
            if totalPoints2 == 7:
                return False
            if totalPoints2 == totalPoints1:
                return True

def main():
    n = input('Please insert number of times to simulate:')
    number = n * 1.0
    win = 0
    while n > 0:
        if winOrLose():
            win += 1
        n -= 1
    print "The probability of winning is", win/number

main()
