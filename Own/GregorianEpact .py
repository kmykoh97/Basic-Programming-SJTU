
#The Gregorian Epact is the number of days between Jan. 1st and the previous 1st quarter moon phase. This value is used to ﬁgure out the date of Easter. It is calculated by these formulas (using int arithmetic): 
#The Gregorian Epact Project
#Created by MyKoh
#2017-09-20

year = input('Please enter a 4-digits year')
c = year / 100
epact = (8 + (c/4) - c + ((8*c + 13) / 25) + 11 * (year % 19)) % 30
print epact