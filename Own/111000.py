#Program to find number of "01"s
#Created by MyKoh
#2017-11-05

#Meng Yit's way
def main1():
    x = raw_input("Please input a series of number")
   
    c=0

    for i in range(len(x)):
        a = 1
        b = 1
        d = 1
        while i+d <= len(x)-1 and x[i] == x[i+d]:
            a += 1
            d += 1
        while i+d+1 <= len(x)-1 and x[i+d] == x[i+d+1]:
            b += 1
            d += 1
        if b >= a:
            #print a*x[i]
            c += 1

    print c-1

#Zhicheng's way
def main2():
    x = raw_input("Please input a series of number:")
    c = 0
    l = []

    for i in range(len(x)):
        if i+1 <= len(x)-1 and x[i] != x[i+1]:
            c += 1
            l.append(i)
    print l
    for i in l:
        a = 1
        b = 2
        while x[i-a] == x[i] and x[i+b] == x[i+1]:
            c +=1
            a +=1
            b +=1
    print "The number of sets: ",c

#main1()
#main2()
