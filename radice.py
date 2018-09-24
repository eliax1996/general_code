import cmath
import math

from math import sqrt


def risolvi_radice(a, b, c):
    "questa funzione stampa a schermo la risoluzione di un equazione di secondo grado"
    radice = sqrt(((b * b) - (4 * a * c)))
    res_1 = (-b - radice) / (2 * a)
    res_2 = (-b + radice) / (2 * a)
    print("radice " + str(res_2))
    print("risultato 1: " + str(res_1))
    print("risultato 2: " + str(res_2))
    return


n = complex(0, -1)
d = complex(1, 1)

print(math.atan(-1))
print((cmath.phase((d))))
risolvi_radice(2.2, -44.6, 128)
