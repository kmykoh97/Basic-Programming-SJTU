# class
class GlobalTime:
    def __init__(self,hour,minute,second,city):
        self.hour = hour
        self.minute = minute
        self.second = second
        self.city = city

    def timeConversion(self):
        city1 = ["London","Madrid","Paris","Istanbul","Moscow","Abu Dhabi","Dhaka","Bangkok","Buenos Aires","New York","Chicago","Los Angles"]
        diff_minus = [8, 7, 7, 5, 5, 4, 2, 1, 11, 12, 13, 15]
        city2 = ["Tokyo", "Melbourne"]
        diff_add = [1,3]
        minute = self.minute
        for i in range(len(city1)):
            if self.city == city1[i]:
                hour = self.hour - diff_minus[i]
        for j in range(len(city2)):
            if self.city == city2[j]:
                hour = self.hour + diff_add[j]
        if self.city == "New Delhi":
            hour = self.hour - 2
            minute = self.minute - 30
        return hour,minute

    def increment(self,hour,minute):
        if minute < 0:
            minute += 60
            hour -= 1
        return hour, minute

    def determineDay(self,hour):
        if hour < 0:
            hour += 24
            print "It's one day before Beijing Day."

        elif hour > 24:
            hour -= 24
            print "It's one day after Beijing Day."
        return hour
    def print_time(self,hour,minute):
        print "%s is %.2d:%.2d:%.2d now." % (self.city, hour, minute,self.second)

print "Please input in 24-hour format"
print
#time = GlobalTime(7,20,30,"London")
x = raw_input(':')
time = GlobalTime(1,20,30,x)
hour,minute = time.timeConversion()
hour,minute = time.increment(hour,minute)
hour = time.determineDay(hour)
time.print_time(hour,minute)
