#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

# ZEN-PYTHON GOLD RULES!
# 1) Keep it simple
# 2) Do one thing well
# 3) Don’t fret too much about performance – plan to optimise later when needed.
# 4) Don’t fight the environment and go with the flow.
# 5) No-one’s Perfect -- Good Enought is Good Enought
# 6) Minor shortcut
# 7) Learn from the masters
# 8) Think Cross-platform
# 9) Stop bugging me (that’s Window’s job). Don’t bother users with details that the machine can handle.
# 10) Extensibility
# 11) Senseless fatalities:
#       Errors should not be fatal. That is, user code should be able to recover from error
#       conditions as long as the virtual machine is still functional. At the same # time, errors should not pass silently.
# 12) Bug off:
#       A bug in the user’s Python code should not be allowed to lead to undefined behavior of the Python interpreter;
#       a core dump is never the user’s fault

# in python anche se fa smadonnare il cristo
# ad un programmatore amante del c style il modo
# di commentare e' usare questo simbolo -> #
#

print("ciao mondo")

# esempio di for di un tipo iterabile
for num in [2, 3, 4, 5]:
    print(num)


# i numeri complessi sono gia' definiti nel core di python
num_complesso = 3 + 4j

# il metodo type ritorna il tipo di oggetto che gli viene passato
print(type(22))
print(type(num_complesso))

# per ottenere l'id di un oggetto usare il metodo id()
print(id(num_complesso))

# gli oggetti lista possono essere ordinati con il metodo sort
# il metodo sort puo' essere esteso con più parametri, ad esempio
# il comparatore o il metodo per invertirla

lista = [2, 3, 1]
print(lista)
lista.sort()
print(lista)
lista.sort(reverse=True)
print(lista)

# per accedere ai metodi e agli attributi e' sufficiente utilizzare il punto
# ricordarsi che un metodo senza le tonde restituisce solo l'indirizzo del metodo
print(num_complesso.conjugate)
print(num_complesso.conjugate())

# per scoprire se un metodo e' invocabile basta usare il metodo callable
print(callable(num_complesso.conjugate))

# num_complesso.conjugate = function:

# ci sono funzioni richiamabili su un insieme di oggetti es:
print(sum(lista))

# la funzione dir(obj) ritorna l'insieme dei metodi principali di un oggetto
print(dir(num_complesso))

# tipologie di stringhe
str1 = "stringa non spezzabile piu su righe"
str2 = 'anche questa'
str3 = '''questa invece
puo essere spezzata
su piu' righe'''
str4 = """ecco
un
altra
stringa su piu' righe"""

# indice di inizio di una sottostringa o lettera
print(str1.index("a"))
print(str1.index("righe"))

# esempio di concatenazione , indexing e stampa di stringhe
print(str1[1])
print(str2[0:20])
print(str3)
print(str4)

# spacchettamento di oggetti iterabili
a, b, c, d = str1[0:4]
print(a)
print(b)
print(c)
print(d)

# contare le occorrenze di una sottostringa
print(str1.count("a"))
print(str1 + " e " + str2)

# gli oggetti str sono immutabili
#str4[1] = 'q'

# le liste invece sono moficabili
lista[1] = 'a'

c = input("dimmi il testo")
print("il testo era:" + c)
