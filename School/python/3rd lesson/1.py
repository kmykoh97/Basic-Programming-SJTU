#Shangji Practice
#Meng Yit Koh
#517030990022

from Tkinter import *

def fileModify():
    #x = raw_input('Insert file name:')
    # y = open('/home/kmykoh97/Desktop/score.txt', 'r+')#(For Ubuntu Linux)
    y = open('score.txt', 'r+')
    z = y.readlines()
    del z[0]
    #print z
    #Put every lines into list:
    a = []
    for i in z:
        for j in range(len(i)):
            if i[j] == '\t':
                a.append(i[j+1:j+3])
    #print a
    #Change some odd values to be true:
    for i in range(len(a)):
        if a[i] == '0\t':
            a[i] = '0'
        elif a[i] == '10':
            a[i] = '100'
    #print a
    #Count summation of different works:
    sum1, sum2, sum3, sum4, counter = 0, 0, 0, 0, 0
    for i in range(0, len(a), 4):
        sum1 = sum1 + float(a[i])
        counter +=1
    for i in range(1, len(a), 4):
        sum2 = sum2 + float(a[i])
    for i in range(2, len(a), 4):
        sum3 = sum3 + float(a[i])
    for i in range(3, len(a), 4):
        sum4 = sum4 + float(a[i])
    #print sum1, sum2, sum3, sum4
    #Count average values of different works:
    avg1, avg2, avg3, avg4 = sum1/counter, sum2/counter, sum3/counter, sum4/counter
    #print avg1, avg2, avg3, avg4
    #Ammend file:
    y.write("Average\t%0.2f\t%0.2f\t%0.2f\t%0.2f" %(avg1, avg2, avg3, avg4))
    y.close()
    return avg1, avg2, avg3, avg4

#fileModify()

def GUI(avg1, avg2, avg3, avg4):
    root = Tk()
    c = Canvas(root, width = 800, height = 1000, bg = 'grey')
    #Graph bar:
    r1 = c.create_rectangle(50, 800, 100, 1000-avg1*10, fill='red')
    r2 = c.create_rectangle(150, 800, 200, 1000-avg2*10, fill='blue')
    r3 = c.create_rectangle(250, 800, 300, 1000-avg3*10, fill='green')
    r4 = c.create_rectangle(350, 800, 400, 1000-avg4*10, fill='yellow')
    #Graph axes:
    l1 = c.create_line(30, 800, 30, 100, arrow=LAST)
    l2 = c.create_line(30, 800, 500, 800, arrow=LAST)
    #Text:
    t1 = c.create_text(50,820,text='work1',anchor=NW)
    t2 = c.create_text(150,820,text='work2',anchor=NW)
    t3 = c.create_text(250,820,text='work3',anchor=NW)
    t4 = c.create_text(350,820,text='work4',anchor=NW)
    t5 = c.create_text(50,150,text=round(avg1,2),anchor=NW)
    t6 = c.create_text(150,150,text=round(avg2,2),anchor=NW)
    t7 = c.create_text(250,150,text=round(avg3,2),anchor=NW)
    t8 = c.create_text(350,150,text=round(avg4,2),anchor=NW)
    t9 = c.create_text(30,80,text='Average')
    t10 = c.create_text(550,800,text='Subjects')
    c.pack()
    root.mainloop()

#GUI()

def main():
    avg1, avg2, avg3, avg4 = fileModify()
    GUI(avg1, avg2, avg3, avg4)

main()
