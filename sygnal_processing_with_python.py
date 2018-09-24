#!/usr/bin/env python3
import platform,plot_function
import math
import fourier_operations

from math import pi

def first_math_function(x):
	if (x < 0 or x > 2):
		return 0
	return 1
	
def second_math_function(x):
	if (x < 2 or x > 4):
		return 0
	return 1
	
print("utilizzo la versione: " + platform.python_version() + "di python")


# stampo le due funzioni
plot_function.set_start_and_end(-10, 10)
#calcolo i punti della funzione
first_function_array = plot_function.calculate_a_function_point(first_math_function)
second_function_array = plot_function.calculate_a_function_point(second_math_function)

result = fourier_operations.linear_convolution(first_function_array[1], second_function_array[1])
plot_function.add_a_list_of_point_to_be_printed((first_function_array[0],result[0:100]))

array_out = (first_function_array[0],result)

#aggiungo i punti al grafico e lo stampo
plot_function.add_a_list_of_point_to_be_printed(first_function_array)
plot_function.add_a_list_of_point_to_be_printed(second_function_array)
plot_function.add_a_list_of_point_to_be_printed(array_out)
plot_function.print_functions_and_point()

#calcolo la convoluzione lineare

#calcolo la convoluzione circolare