#World Time
#Created by MyKoh
#2017-11-06

#Using class
class worldTime:

    def _init_(self, hour, minutes, seconds):
        self.hour = hour
        self.minutes = minutes
        self.seconds = seconds

    def getTime(self):
        self.hour = input('Insert hour')
        self.minutes = input('Insert minutes')
        self.seconds = input('Insert seconds')

    def timeConversion(self, city):
        self.city = raw_input("City:")
        countryList = ['london', 'japan', 'italy', 'german', 'new york']
        UTC = [0, 9, 1, 1, 5]
        for i in range(len(countryList)):
            if countryList[i].lower() == self.city:
                self.hour = self.hour - 8 + UTC[i]

    def day(self):
        if self.hour < 0:
            print 'It is previous day'
            self.hour += 24
        elif self.hour > 24:
            print 'It is the next day'
            self.hour -= 24

    def printTime(self):
        print "%s is %d.%d.%d now" % (self.city, self.hour, self.minutes, self.seconds)

time = worldTime()
print "Please input Beijing time in 24-hour format"
print
time.getTime()
time.city = raw_input("City:")
time.timeConversion()
time.day()
time.printTime()









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