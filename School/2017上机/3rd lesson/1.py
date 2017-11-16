#Shangji Practice
#Meng Yit Koh
#517030990022

from Tkinter import *

def fileModify():
    #x = raw_input('Insert file name:')
    y = open('/home/kmykoh97/Desktop/score.txt', 'r+')
    z = y.readlines()
    del z[0]
    #print z
    a = []
    for i in z:
        for j in range(len(i)):
            if i[j] == '\t':
                a.append(i[j+1:j+3])
    #print a
    for i in range(len(a)):
        if a[i] == '0\t':
            a[i] = '0'
        elif a[i] == '10':
            a[i] = '100'
    #print a
    sum1,sum2, sum3, sum4, counter = 0, 0, 0, 0, 0
    for i in range(0, len(a), 3):
        sum1 = sum1 + int(a[i])
        counter +=1
    for i in range(1, len(a), 3):
        sum2 = sum2 + float(a[i])
    for i in range(2, len(a), 3):
        sum3 = sum3 + float(a[i])
    for i in range(3, len(a), 3):
        sum4 = sum4 + float(a[i])
    #print sum1, sum2, sum3, sum4
    avg1, avg2, avg3, avg4 = sum1/counter, sum2/counter, sum3/counter, sum4/counter
    #print avg1, avg2, avg3, avg4
    y.write("Average\t%0.2f\t%0.2f\t%0.2f\t%0.2f" %(avg1, avg2, avg3, avg4))
    y.close()
    return avg1, avg2, avg3, avg4

#fileModify()

def GUI(avg1, avg2, avg3, avg4):
    root = Tk()
    c = Canvas(root, width = 800, height = 800, bg = 'white')
    r1 = c.create_rectangle(50, avg1*10, 100, 100)
    r2 = c.create_rectangle(150, avg2*10, 200, 100)
    r3 = c.create_rectangle(250, avg3*10, 300, 100)
    r4 = c.create_rectangle(350, avg4*10, 400, 100)
    c.pack()
    root.mainloop()

#GUI()

def main():
    avg1, avg2, avg3, avg4 = fileModify()
    GUI(avg1, avg2, avg3, avg4)

main()
