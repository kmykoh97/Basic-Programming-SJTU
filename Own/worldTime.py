#World Time
#Created by MyKoh
#2017-11-06

#Using class
class worldTime:

    def __init__(self, UTC, hour, minutes, seconds):
        self.UTC = UTC
        self.hour = hour
        self.minutes = minutes
        self.seconds = seconds

    def timeConversion(self):
        self.hour = self.hour - 8 + self.UTC
        if self.hour < 0:
            print 'It is previous day'
            self.hour += 24
        elif self.hour > 24:
            print 'It is the next day'
            self.hour -= 24
        print "%s is %d.%d.%d now" % (x, self.hour, self.minutes, self.seconds)

print "Please input Beijing time in 24-hour format"
print
a = input("Please insert hour in Beijing now:")
b = input("Please insert minutes in Beijing now:")
c = input("Please insert seconds in Beijing now:")
london = worldTime(0,a,b,c)
japan = worldTime(9,a,b,c)
italy = worldTime(1,a,b,c)
german = worldTime(1,a,b,c)
newyork = worldTime(5,a,b,c)
x = input('Insert your country:')
x.timeConversion()

#Using function
def main():
    x = raw_input('Please insert country:')
    beijingTime = input('Please insert 24H time in beijng now:')
    countryList = ['london', 'japan', 'italy', 'german', 'new york']
    UTC = [0, 9, 1, 1, 5]
    for i in range(len(countryList)):
        if countryList[i].lower() == x:
            newTime = beijingTime - 8 + UTC[i]
    return newTime

#main()
