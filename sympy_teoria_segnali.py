from sympy import *

init_printing(use_unicode=False, wrap_inline=False, no_global=True, use_latex=True)

x = Symbol('x')
text = integrate(sin(x)**3, x)

print(pretty(text))
