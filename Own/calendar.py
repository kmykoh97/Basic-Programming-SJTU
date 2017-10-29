#Calendar Program
#Created by MyKoh
#2017-10-26

def leapYear(y):
    count = 0
    for i in range(1, y):
        if i%4 == 0 and (i%100 != 0 or i%400 == 0):
            count += 1
    return count

def daysBeforeY(y):
    numberOfDays = (y-1) * 365 + leapYear(y)
    #print numberOfDays
    return numberOfDays

def firstDayInY(y):
    endOfLastYear = daysBeforeY(y) % 7
    firstDayOfY = endOfLastYear + 1
    if firstDayOfY == 7:
        firstDayOfY = 0
    return firstDayOfY

def frame(y, n):
    N = n+1
    N = N % 7
    print
    print "========== " + str(y) + " =========== "
    months = ["Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"]
    noOfDaysPerMonth = [31,28,31,30,31,30,31,31,30,31,30,31]
    for i in range(12):
        print "           %s       " % (months[i])
        print "Mon Tue Wed Thu Fri Sat Sun"
        if y%4 == 0 and (y%100 != 0 or y%400 == 0):
            noOfDaysPerMonth[1] = 29
        else:
            noOfDaysPerMonth[1] = 28
        if N == 0:
            N = 7
        if N == 1:
            N = 8
        for k in range(N-2):
            print  "%3s" % (' '),
        for j in range(1, noOfDaysPerMonth[i]+1):
            print  "%3s" % (str(j)),
            if (N-2+j)%7 == 0:
                print
        N = N + noOfDaysPerMonth[i]
        N = N % 7
        print
        print

def main():
    y = input('Please insert year:')
    n = firstDayInY(y)
    frame(y, n)

main()