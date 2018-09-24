n_quantico = input("dimmi il numero quantico principale: ")
risp = raw_input("li stampo tutti? (si o no): ")

if (risp == "si"):
    risp = True
else:
    risp = False

print("""struttura: { numero quantico principale , numero quantico azimutale , numero quantico magnetico , spin }""")

num = 0

for n in range(1, n_quantico + 1):

    if (risp == False) and (n != n_quantico):
        break

    print("numero quantico: " + str(n))
    for m in range(0, n):
        for l in range(-m, m + 1):
            num += 2
            print("{ " + str(n) + " , " + str(m) + " , " + str(l) + " , 0 }")
            print("{ " + str(n) + " , " + str(m) + " , " + str(l) + ", 1 }")

print("le configurazioni dei numeri quantici sono: " + str(num))
