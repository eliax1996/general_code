from graphviz import Digraph

#leggo il file del grafo
righe = open('grafo.txt').read().split('\n')

#scarto la prima riga
righe = righe[1:]

#separo gli archi dai nodi
nodi = righe[0:14]
righe = righe[14:]

#costruisco il grafo
dot = Digraph(comment='Tema APA')

#aggiungo i nodi al grafo
for nodo in nodi:
	dot.node(nodo, nodo)
	
edges = []

for riga in righe:
	dati = riga.split(' ')
	edges.append(((dati[0], dati[1]), {'label': dati[2]}))

for e in edges:
	if isinstance(e[0], tuple):
		dot.edge(*e[0], **e[1])
	else:
		dot.edge(*e)

print(dot.source)
dot.render('test-output/round-table.gv', view=True)