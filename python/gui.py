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

def cambtnclick():
	f.write("c " + camin.get() + " " + camin2.get() + " 70\n")

def sbtnclick():
	f.write("sp " + sin1.get() + " " + sin2.get() + " 255,0,0\n")

def plbtnclick():
	f.write("pl " + plin1.get() + " " + plin2.get() + " 0,255,0\n")

def sqbtnclick():
	f.write("sq " + sqin1.get() + " " + sqin2.get() + " " + sqin3.get() + " 0,0,255\n")

def trbtnclick():
	f.write("tr " + trin1.get() + " " + trin2.get() + " " + trin3.get() + " 0,255,255\n")

def cybtnclick():
	f.write("cy " + cyin1.get() + " " + cyin2.get() + " " + cyin3.get() + " " + cyin4.get() + " 255,255,0\n")

def mainbtnclick():
	f.close()
	window2.quit()

def clicked3():
	global f 
	f = open("scenes/tmp.rt", "w")
	global window2
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
	abtn.grid(column = 4, row = 3)

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
	camlab1 = Label(window2, text = "Координаты камеры")
	camlab2 = Label(window2, text = "Вектор камеры")
	global camin, camin2
	camin = Entry(window2)
	camin2 = Entry(window2)
	cambtn = Button(window2, text = "Добавить камеру", command = cambtnclick)
	camlab1.grid(column = 0, row = 7)
	camin.grid(column = 1, row = 7)
	camlab2.grid(column = 2, row = 7)
	camin2.grid(column = 3, row = 7)
	cambtn.grid(column = 4, row = 7)
	clab3.grid(column = 0, row = 6)
	
	"""Сфера"""
	clab4 = Label(window2, text = "Сфера")
	clab4.grid(column = 0, row = 8)
	slab1 = Label(window2, text = "Координаты центра")
	slab2 = Label(window2, text = "Радиус сферы")
	global sin1, sin2
	sin1 = Entry(window2)
	sin2 = Entry(window2)
	sbtn = Button(window2, text = "Добавить сферу", command = sbtnclick)
	slab1.grid(column = 0, row = 9)
	sin1.grid(column = 1, row = 9)
	slab2.grid(column = 2, row = 9)
	sin2.grid(column = 3, row = 9)
	sbtn.grid(column = 4, row = 9)

	"""Плоскость"""
	clab5 = Label(window2, text = "Плоскость")
	clab5.grid(column = 0, row = 10)
	pllab1 = Label(window2, text = "Координаты точки")
	pllab2 = Label(window2, text = "Вектор нормали")
	global plin1, plin2
	plin1 = Entry(window2)
	plin2 = Entry(window2)
	plbtn = Button(window2, text = "Добавить плоскость", command = plbtnclick)
	pllab1.grid(column = 0, row = 11)
	pllab2.grid(column = 2, row = 11)
	plin1.grid(column = 1, row = 11)
	plin2.grid(column = 3, row = 11)
	plbtn.grid(column = 4, row = 11)
	
	"""Квадрат"""
	clab6 = Label(window2, text = "Квадрат")
	clab6.grid(column = 0, row = 12)
	sqlab1 = Label(window2, text = "Координаты центра")
	sqlab2 = Label(window2, text = "Вектор нормали")
	sqlab3 = Label(window2, text = "Длина стороны")
	global sqin1, sqin2, sqin3
	sqin1 = Entry(window2)
	sqin2 = Entry(window2)
	sqin3 = Entry(window2)
	sqbtn = Button(window2, text = "Добавить квадрат", command = sqbtnclick)
	sqlab1.grid(column = 0, row = 13)
	sqlab2.grid(column = 2, row = 13)
	sqlab3.grid(column = 4, row = 13)
	sqin1.grid(column = 1, row = 13)
	sqin2.grid(column = 3, row = 13)
	sqin3.grid(column = 5, row = 13)
	sqbtn.grid(column = 6, row = 13)

	"""Треугольник"""
	clab7 = Label(window2, text = "Треугольник")
	clab7.grid(column = 0, row = 14)
	trlab1 = Label(window2, text = "Координаты первой точки")
	trlab2 = Label(window2, text = "Координаты второй точки")
	trlab3 = Label(window2, text = "Координаты третей точки")
	global trin1, trin2, trin3
	trin1 = Entry(window2)
	trin2 = Entry(window2)
	trin3 = Entry(window2)
	trbtn = Button(window2, text = "Добавить треугольник", command = trbtnclick)
	trlab1.grid(column = 0, row = 15)
	trlab2.grid(column = 2, row = 15)
	trlab3.grid(column = 4, row = 15)
	trin1.grid(column = 1, row = 15)
	trin2.grid(column = 3, row = 15)
	trin3.grid(column = 5, row = 15)
	trbtn.grid(column = 6, row = 15)

	"""Циллиндр"""
	clab8 = Label(window2, text = "Циллиндр")
	clab8.grid(column = 0, row = 16)
	cylab1 = Label(window2, text = "Координаты центра циллиндра")
	cylab2 = Label(window2, text = "Координаты вектора направления")
	cylab3 = Label(window2, text = "Диаметр циллиндра")
	cylab4 = Label(window2, text = "Высота циллиндра")
	global cyin1, cyin2, cyin3, cyin4
	cyin1 = Entry(window2)
	cyin2 = Entry(window2)
	cyin3 = Entry(window2)
	cyin4 = Entry(window2)
	cybtn = Button(window2, text = "Добавить циллиндр", command = cybtnclick)
	cylab1.grid(column = 0, row = 17)
	cylab2.grid(column = 2, row = 17)
	cylab3.grid(column = 0, row = 18)
	cylab4.grid(column = 2, row = 18)
	cyin1.grid(column = 1, row = 17)
	cyin2.grid(column = 3, row = 17)
	cyin3.grid(column = 1, row = 18)
	cyin4.grid(column = 3, row = 18)
	cybtn.grid(column = 4, row = 18)
	global mainbtn
	mainbtn = Button(window2, text = "Завершить", command = mainbtnclick)
	mainbtn.grid(column = 0, row = 19)
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