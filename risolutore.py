import sympy as sp
from sympy import symbols, cos, sin

a, b, c = symbols('a b c')
v1, a1, f1 = symbols('v1 a1 f1')
w, t = symbols('w t')

g1 = 2*a + 35*c
g2 = 15*a+c**2


sp.solvers.solve((g1,g2), (a, b, c))