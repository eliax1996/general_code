#!/usr/bin/env python
# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
import scipy.fftpack


# calcolo del linspace

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


def math_function(x):
    if (x < 1 and x > 0):
        return 1
    return 0
    # np.log10(x) + np.abs(x / x**2)
    # per divertirti prova anche con:
    # np.exp(x)
    # np.log2(x)
    # np.abs(x)
    # ...


# definizione della funzione
start = -1
end = 2
number = 100000
min_value = 0

f = function_set_point(math_function, start, end, number)
plt.title(u"Funzione del tempo")
plt.ylabel(u"intensità funzione")
plt.xlabel(u"asse dei tempi")
plt.plot(f[0], f[1])

yf = scipy.fftpack.fft(f[1])
xf = f[0]

fig, ax = plt.subplots()
ax.plot(xf, np.real(yf))
ax.plot(xf, np.imag(yf))
plt.title(u"Trasformata di Fourier asse reale e immaginario")
plt.ylabel(u"intensità funzione")
plt.xlabel(u"asse delle frequenze")
plt.show()
