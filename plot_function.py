import matplotlib.pyplot as plt

_start = -(2)
_end = 2
_number = 100
_list_of_function = []
_list_of_point = []



def set_start_and_end(start,end):
	global _start,_end
	_start = start
	_end = end


def calculate_a_function_point(math_function):
	dx = float(_end - _start) / _number
	start = _start / dx
	end = _end / dx

	x_list = []
	y_list = []

	for x in range(int(start), int(end)):
		x_list.append(x * dx)
		y_list.append(math_function(x * dx))

	array = (x_list, y_list)

	return array

def add_a_function_to_print(math_function):
	global _list_of_function
	_list_of_function.append(math_function)

def void_functions_to_print():
	global _list_of_function
	_list_of_function = []
	
def void_point_to_print():
	global _list_of_point
	_list_of_point = []
	
def add_a_list_of_point_to_be_printed(array):
	global _list_of_point
	_list_of_point.append(array)
	

def print_functions_and_point():
	global _list_of_function
	
	for f in _list_of_function:
		point = calculate_a_function_point(f)
		plt.plot(point[0],point[1])
		
	for p in _list_of_point:
		plt.plot(p[0],p[1])
		
	plt.show()


# passo alla funzione generatrice dei punti e
# dei valori corrispettivi ai punti l'inizio
# la fine e il numero di punti da calcolare
# e come primo parametro l'indirizzo della funzione
# di valutazione (funzione matematica da plottare)

# stampo per punti
#plt.axis([start, end, min_value, max_value])
# plt.show()

# stampo per interpolazione lineare
#plt.plot(f[0], f[1])
# plt.show()
