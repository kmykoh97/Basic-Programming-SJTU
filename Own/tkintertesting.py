from Tkinter import *

def GUI11():
    root = Tk()
    c = Canvas(root, width = 600, height = 1000, bg = 'white')

    r1 = c.create_rectangle(50, 500, 100, 100)
    r2 = c.create_rectangle(150, 800, 200, 100)
    r3 = c.create_rectangle(250, 300, 300, 100)
    r4 = c.create_rectangle(350, 900, 400, 100)
    c.pack()
    root.mainloop()


GUI11()
