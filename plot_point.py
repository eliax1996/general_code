import matplotlib.pyplot as plt
import numpy as np
import math
from math import pi


def function_set_point(function, start, end, number, k):
    dx = float(end - start) / number
    start = start / dx
    end = end / dx

    x_list = []
    y_list = []

    for x in range(int(start), int(end)):
        x_list.append(x * dx)
        y_list.append(math_function(x * dx, k))

    array = (x_list, y_list)

    return array


def mia_function(x):
    math.sin(pi * x * 100000) / math.sin(pi * x)


def math_function(x, k):
    try:
        return math.sin(pi * x * k) / math.sin(pi * x)
    except:
        return k  # np.log10(x) + np.abs(x / x**2)
    # per divertirti prova anche con:
    # np.exp(x)
    # np.log2(x)
    # np.abs(x)
    # ...


start = -(0.5)
end = 0.5
number = 10000
min_value = 0

# passo alla funzione generatrice dei punti e
# dei valori corrispettivi ai punti l'inizio
# la fine e il numero di punti da calcolare
# e come primo parametro l'indirizzo della funzione
# di valutazione (funzione matematica da plottare)

print(start)
print(end)

f = function_set_point(mia_function, start, end, number, 10000)
print(f[0])
print(f[1])
plt.plot(f[0], f[1])
plt.show()

for k in range(0, 40):
    f = function_set_point(mia_function, start, end, number, k)
    print(f[0])
    print(f[1])
    plt.plot(f[0], f[1])
    plt.show()

# trovo valore massimo elaborato
max_value = max(f[1])

# stampo per punti
#plt.axis([start, end, min_value, max_value])
# plt.show()

# stampo per interpolazione lineare
#plt.plot(f[0], f[1])
# plt.show()
