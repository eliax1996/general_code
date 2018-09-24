import matplotlib.pyplot as plt
import numpy as np
import math
from math import pi


def function_set_point(function, start, end, number):
	dx = float(end - start) / number
	start = start / dx
	end = end / dx

	x_list = []
	y_list = []

	for x in range(int(start), int(end)):
		x_list.append(x * dx)
		y_list.append(function(x * dx))

	array = (x_list, y_list)

	return array

def first_function(x):
	return math.sin(2*math.pi*x/5)
	
def second_function(x):
	return 1

def plot_function(x,y):
	plt.plot(x, y)
	plt.show()

def plot_function_dot(x,y):
	plt.axis([min(x)-1, max(x)+1, min(y)-1, max(y)+1])
	plt.plot(x, y,'ro')
	plt.show()
	
def linear_convolution(x1,y1,x2,y2):
	len_1 = len(x1)
	len_2 = len(x2)
	
	

function_one = function_set_point(first_function,0,4,4)
plot_function_dot(function_one[0], function_one[1])
function_two = function_set_point(second_function,0,2,2)
plot_function_dot(function_two[0], function_two[1])








