#Calendar Program
#Created by MyKoh
#2017-10-23

x = input('Year:')

def leapYear():
    if x % 4 != 0:
        daysPerYear = 365
    else:
        daysPerYear = 366

def calendar():
    monday = 1
    tuesday = 2
    wednesday = 3
    thursday = 4
    friday = 5
    saturday = 6
    sunday = 7
    totalDays = 0
    for i in range(1, x-1):
        if i % 4 != 0:
            daysPerYear = 365
        else:
            daysPerYear = 366
        totalDays += daysPerYear
    print totalDays % 7

calendar()