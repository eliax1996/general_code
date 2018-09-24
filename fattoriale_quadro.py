import matplotlib.pyplot as plt
import numpy as np


def function_set_point(function, start, end, number):
    dx = float(end - start) / number
    start = start / dx
    end = end / dx

    x_list = []
    y_list = []

    for x in range(int(start), int(end)):
        x_list.append(x * dx)
        y_list.append(math_function(x * dx))

    array = (x_list, y_list)

    return array


def fact(x):
    if (x <= 1):
        return 1

    return x * fact(x - 1)


def math_function(x):
    if (x < 15):
        return 0
    print(str(x) + "  " + str(fact(x - 15)))
    return fact(x - 15)  # np.log10(x) + np.abs(x / x**2)
    # per divertirti prova anche con:
    # np.exp(x)
    # np.log2(x)
    # np.abs(x)
    # ...


start = 0
end = 25
number = 1000
min_value = 0

# passo alla funzione generatrice dei punti e
# dei valori corrispettivi ai punti l'inizio
# la fine e il numero di punti da calcolare
# e come primo parametro l'indirizzo della funzione
# di valutazione (funzione matematica da plottare)
f = function_set_point(math_function, start, end, number)
plt.plot(f[0], f[1], 'ro')

# trovo valore massimo elaborato
max_value = max(f[1])

# stampo per punti
plt.axis([start, end, min_value, max_value])
plt.show()

# stampo per interpolazione lineare
plt.plot(f[0], f[1])
plt.show()
