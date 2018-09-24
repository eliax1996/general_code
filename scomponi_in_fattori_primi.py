#!/usr/bin/python

def trova_primi(x):
    verifica=0
    for trova in range(2,x):
        if x%trova==0:
            verifica=verifica+1
    if verifica==0:
        return True
    else:
        return False
def trova_n(x):
    a=2
    z=x
    lista=[1]
    indice=1
    while z!=1:
        if trova_primi(a)==True and z%a==0:
            lista[indice:indice]=[a]
            z=z/a
            indice=indice+1
        else:
            a=a+1
        risu=""
        cont=0
        for numero in lista:
            lung=len(lista)
            cont=cont+1
            if cont==lung:
                risu=risu+str(numero)
            elif cont!=lung and numero!=1:
                risu=risu+str(numero)+" * "
    print x,"=",risu
while True:
    numero=input("Enter the number: ")
    if numero==-1:
        break
    if trova_primi(numero)==True:
        print "This is a prime number!"
    else:
        trova_n(numero)
