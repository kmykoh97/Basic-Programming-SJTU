#Calendar Program
#Created by MyKoh
#2017-10-26

x = input('Year:')

def leapYear():
    if x % 4 != 0 or :
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

#sample
def main():		
	year = getYear()	
	w = firstDay(year)	
	printCalendar(year,w)

def getYear():
	print "本程序打印年历. "
	year = input("请输入年份(1900后):")
	return year
    
def firstDay(year):
	k = leapyears(year)
	n = (year-1900) * 365 + k
	return (n + 1) % 7
    
def printCalendar(year,w):
	print
	print "===== " + str(year) + " ===== "
	first = w
	for month in range(12):
		heading(month)
		first = oneMonth(year,month,first)
		
def leapyears(year):
	count = 0
	for y in range(1900,year):
		if y%4 == 0 and (y%100 != 0 or y%400 == 0):
			count = count + 1
	return count
    
def heading(m):
	months = ["Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"]
	print "       %s       " % (months[m])
	print "Mon Tue Wed Thu Fri Sat Sun"
	
def oneMonth(year, month, first):
	d = days(year,month)
	frame = layout(first,d)
	printMonth(frame)
	return (first + d) % 7
    
def days(y,m):
	month_days = [31,28,31,30,31,30,31,31,30,31,30,31]
	d = month_days[m]
	if (m == 1) and (y%4 == 0 and \
		(y%100 != 0 or y%400 == 0)):
		d = d + 1
	
	return d
    
def layout(first,d):
	frame = 42 * [""]
	if first == 0:
		first = 7
	j = first - 1
	for i in range(1,d+1):
		frame[j] = i
		j = j + 1
	return frame
    
def printMonth(frame):
	for i in range(42):
		print "%3s" % (frame[i]), 
		if (i+1)%7 == 0:
			print
main()
