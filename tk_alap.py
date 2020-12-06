#! /usr/bin/python3

from tkinter import *

root = Tk()
root.title("tEsT")
root.geometry('200x200')
root.config(bg='green')

l_test = Label(root, text="Helo belo")
l_test.pack()

l_uj = Label(root,text="Ez mar uj verzio")
l_uj.pack()

b_exit = Button(root,text="Exit",command=root.quit)
b_exit.pack()

root.mainloop()
