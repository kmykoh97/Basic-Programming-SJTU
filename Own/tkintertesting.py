from Tkinter import *

def GUI11():
    root = Tk()
    c = Canvas(root, width = 600, height = 1000, bg = 'white')

    r1 = c.create_rectangle(50, 450, 100, 200)
    r2 = c.create_rectangle(150, 450, 200, 300)
    # r3 = c.create_rectangle(250, 100, 300, 300)
    # r4 = c.create_rectangle(350, 100, 400, 900)
    c.pack()
    root.mainloop()


GUI11()
