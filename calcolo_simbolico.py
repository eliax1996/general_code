from sympy import fourier_transform, exp
from sympy import *
from sympy.abc import x, k

pprint(fourier_transform(exp(-x**2), x, k))
#sqrt(pi) * exp(-pi**2 * k**2)

fourier_transform(exp(-x**2), x, k, noconds=False)
#(sqrt(pi) * exp(-pi**2 * k**2), True)
