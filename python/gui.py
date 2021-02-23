from tkinter import *
from tkinter.ttk import Combobox
import os

def clicked1():
	os.system("./miniRT scenes/" + combo.get())

def clicked2():
	os.system("./miniRT scenes/" + combo.get() + " --save")

def resbtnclick():
	f.write("R " + resin1.get() + " " + resin2.get() + '\n')

def abtnclick():
	f.write("A " + ain.get() + " 255,255,255\n")

def lbtnclick():
	f.write("l " + lin1.get() + " " + lin2.get() + " 255,255,255")

def clicked3():
	global f 
	f = open("scenes/tmp.rt", "w")
	window2 = Tk()
	window.title("Создание сцены")
	"""Разрешение"""
	clab = Label(window2, text = "Разрешение")
	clab.grid(column = 0, row = 0)
	res1 = Label(window2, text = 'Ширина')
	res2 = Label(window2, text = 'Высота')
	global resin1
	resin1 = Entry(window2)
	global resin2
	resin2 = Entry(window2)
	res1.grid(column = 0, row = 1)
	res2.grid(column = 3, row = 1)
	resin1.grid(column = 1, row = 1)
	resin2.grid(column = 4, row = 1)
	resbtn = Button(window2, text = "Добавить разрешение", command = resbtnclick)
	resbtn.grid(column = 5, row = 1)

	"""Ambient"""
	clab1 = Label(window2, text = "Ambient")
	clab1.grid(column = 0, row = 2)
	alab = Label(window2, text = "Интенсивность света")
	alab.grid(column = 0, row = 3)
	global ain 
	ain = Entry(window2)
	ain.grid(column = 1, row = 3)
	abtn = Button(window2, text = 'Добавить Ambient', command = abtnclick)
	abtn.grid(column = 2, row = 3)

	"""Свет"""
	clab2 = Label(window2, text = "Свет")
	clab2.grid(column = 0, row = 4)
	llab1 = Label(window2, text = "Координаты точки")
	llab2 = Label(window2, text = "Интенсивность цвета")
	global lin1, lin2
	lin1 = Entry(window2)
	lin2 = Entry(window2)
	lbtn = Button(window2, text = 'Добавить cвет', command = lbtnclick)
	llab1.grid(column = 0, row = 5)
	llab2.grid(column = 2, row = 5)
	lin1.grid(column = 1, row = 5)
	lin2.grid(column = 3, row = 5)
	lbtn.grid(column = 4, row = 5)
	"""Камера"""
	clab3 = Label(window2, text = "Камера")
	clab3.grid(column = 0, row = 6)
	clab4 = Label(window2, text = "Сфера")
	clab4.grid(column = 0, row = 8)
	clab5 = Label(window2, text = "Плоскость")
	clab5.grid(column = 0, row = 10)
	clab6 = Label(window2, text = "Квадрат")
	clab6.grid(column = 0, row = 12)
	clab7 = Label(window2, text = "Треугольник")
	clab7.grid(column = 0, row = 14)
	clab8 = Label(window2, text = "Циллиндр")
	clab8.grid(column = 0, row = 16)
	window2.mainloop()
	f.close()

os.system("make linux")
os.system("cd scenes && ls > ../python/scenelist.txt && cd ..")
window = Tk()
window.title("miniRT")
labl = Label(window, text = "Выберите сцену")
labl.grid(column = 0, row = 0)
labl2 = Label(window, text = "Создание новой сцены")
labl2.grid(column = 1, row = 2)
btn1 = Button(window, text = "Запуск сцены", command = clicked1)
btn1.grid(column = 1, row = 1)
btn2 = Button(window, text = "Создание изображения", command = clicked2)
btn2.grid(column = 2, row = 1)
btn3 = Button(window, text = "Создать сцену", command = clicked3)
btn3.grid(column = 1, row = 3)
window.geometry('800x800')
combo = Combobox(window)
with open('python/scenelist.txt', 'r') as f:
	combo['values'] = f.read().splitlines()
combo.grid(column = 0, row = 1)
window.mainloop()