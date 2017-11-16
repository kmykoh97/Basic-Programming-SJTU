#World Time
#Created by MyKoh
#2017-11-06

#Using My class
class worldTime:

    def __init__(self, UTC, hour, minutes, seconds,country):
        self.UTC = UTC
        self.hour = hour
        self.minutes = minutes
        self.seconds = seconds
        self.country = country

    def timeConversion(self):
        self.hour = self.hour - 8 + self.UTC
        if self.hour < 0:
            print 'It is previous day'
            self.hour += 24
        elif self.hour > 24:
            print 'It is the next day'
            self.hour -= 24

        print "%s is %s.%s.%s now" % (self.country, self.hour, self.minutes, self.seconds)

print "Please input Beijing time in 24-hour format"
print
a = input("Please insert hour in Beijing now:")
b = input("Please insert minutes in Beijing now:")
c = input("Please insert seconds in Beijing now:")
x = input('Insert your country:')
london = worldTime(0,a,b,c,str(x))
# japan = worldTime(9,a,b,c,str(x))
# italy = worldTime(1,a,b,c,str(x))
# german = worldTime(1,a,b,c,str(x))
# newyork = worldTime(5,a,b,c,str(x))
london.timeConversion()

# #Using function
# def main():
#     x = raw_input('Please insert country:')
#     beijingTime = input('Please insert 24H time in beijng now:')
#     countryList = ['london', 'japan', 'italy', 'german', 'new york']
#     UTC = [0, 9, 1, 1, 5]
#     for i in range(len(countryList)):
#         if countryList[i].lower() == x:
#             newTime = beijingTime - 8 + UTC[i]
#     return newTime
#
# # main()
#
# #ZC way
# class GlobalTime:
#     def __init__(self,hour,minute,second,city):
#         self.hour = hour
#         self.minute = minute
#         self.second = second
#         self.city = city
#
#     def timeConversion(self):
#         city1 = ["London","Madrid","Paris","Istanbul","Moscow","Abu Dhabi","Dhaka","Bangkok","Buenos Aires","New York","Chicago","Los Angles"]
#         diff_minus = [8, 7, 7, 5, 5, 4, 2, 1, 11, 12, 13, 15]
#         city2 = ["Tokyo", "Melbourne"]
#         diff_add = [1,3]  ``
#         minute = self.minute
#         for i in range(len(city1)):
#             if self.city == city1[i]:
#                 hour = self.hour - diff_minus[i]
#         for j in range(len(city2)):
#             if self.city == city2[j]:
#                 hour = self.hour + diff_add[j]
#         if self.city == "New Delhi":
#             hour = self.hour - 2
#             minute = self.minute - 30
#         return hour,minute
#
#     def increment(self,hour,minute):
#         if minute < 0:
#             minute += 60
#             hour -= 1
#         return hour, minute
#
#     def determineDay(self,hour):
#         if hour < 0:
#             hour += 24
#             print "It's one day before Beijing Day."
#
#         elif hour > 24:
#             hour -= 24
#             print "It's one day after Beijing Day."
#         return hour
#     def print_time(self,hour,minute):
#         print "%s is %.2d:%.2d:%.2d now." % (self.city, hour, minute,self.second)
#
# print "Please input in 24-hour format"
# print
# #time = GlobalTime(7,20,30,"London")
# time = GlobalTime(1,20,30,"New Delhi")
# hour,minute = time.timeConversion()
# hour,minute = time.increment(hour,minute)
# hour = time.determineDay(hour)
# time.print_time(hour,minute)
