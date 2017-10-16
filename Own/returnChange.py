#Coins Return Changes Calculation Program
#Created by MyKoh
#2017-10-17

def main():
    x = float(input('Please insert the price < $1: '))
    change = 1.0 - x
    counter1 = 0
    counter2 = 0
    counter3 = 0
    counter4 = 0
    counter5 = 0
    counter6 = 0
    while change - 0.5 >= 0:
        counter1 += 1
        change -= 0.5
    while change - 0.2 >= 0:
        counter2 += 1
        change -= 0.2
    while change - 0.1 >= 0:
        counter3 += 1
        change -= 0.1
    while change - 0.05 >= 0:
        counter4 += 1
        change -= 0.05
    while change - 0.02 >= 0:
        counter5 += 1
        change -= 0.02
    while change - 0.01 >= 0:
        counter6 += 1
        change -= 0.01
    print "changes are: " + str(counter1) + '-0.5 ' + str(counter2) + '-0.2 ' + str(counter3) + '-0.1 ' + str(counter4) + '-0.05 ' + str(counter5) + '-0.02 ' + str(counter6) + '-0.01'

main()
