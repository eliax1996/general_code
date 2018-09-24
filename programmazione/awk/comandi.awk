#!/usr/bin/awk -f
/*
 ----------------------------------riassunto-----------------------------------------

 -f vuol dire comandi in righe successive

 RS = record separator, specifica il carattere separatore es begin{ FS = "ciao"}

 NR = numero righe passate da awk
 FNR = file number raw numero di righe usate nel nuovo file
 NF = number of fields numero di campo attraversato

 $0 variabile intera riga, $1 variabile primo campo, $2
variabile secondo campo ecc ecc fino a $NF ultimo campo, sono inizializzati ogni riga nuova

  comandi:
  condizione azione

  ogni comando è fatto su ogni riga se sulla riga la condizione è vera


  condizione senza azione --> stampa riga

  azione senza condizione --> esegue l'azione sempre

 condizioni ammissibili:
 /RegularExpression/ {azione}
 espressionelogica {azione}
 espressione1,espressione2 {azione} (esegue l'azione da quando l'espressione 1 è vera, fino a quando l'espressione 2 è vera)

 BEGIN { azioni } (azioni fatte prima di leggere il file)
 END { azioni } (azioni fatte alla fine della lettura del file )

//

 esempio di condizioni

$2 ~ /foo/ contiene foo
$2 == "foo" uguale a foo

$1=="rm",$2=="rs" appena incontri a $1 rm fino a quando a $2 non incontri rs fai l'azione

 ARGV[2] variabile contenente il secondo nome file
 ARGC conteggio del numero di variabili

per usare una variabile passata come linea di comando tendenzialmente si mette la variabile come ultimo argomento e si lancia lo script
poi si preleva il valore della variabile in questo modo:

BEGIN {
    var = ARGV[ARGC-1]
    ARGC = ARGC-1
     oppure al posto di decrementare ARGC
    ARGV[ARGC-1] = ""
}

 per stampare con un andare a capo dopo
print var1 var2 [> file]
printf "\t%d",var1  uguale ma formattato
printf "   "

exit  esce dal file
next  prosegue sulla riga successiva


i vettori sono hash-table
si assegnano e si usano

vet["a"] = 2

delete vet["a"]

notare che quando si scrive:
mat[i1,i2]
diventa:
mat[i1@i2]

operatore in
if (index1,index2) in array

diventa
if index1@index2 in array

cicla in tutti gli indici
con ordine casuale
for (index in array)


gli array sono concatenati con la variabile SUBSEP

si può usare la funzione split
che funziona così:
split(index,v,SUBSEP)

prende l'index, lo divide in subsep e lo mette in v


funzione getline:
getline var [<altroFile]
prendo la linea successiva del file corrente se non specifico l'altro file e lo metto in var


outputcomando = "comando eseguito dal sistema operativo"

while(outputcomando | getline >0){
    ...
}

indice_inizio_occorrenza = match("stringa","occorrenza")

close(outputcomando)
-----------------------------------------fine---------------------------
*/

BEGIN {

    total = 0
    da_stampare = 0

    while(getline ARGV[ARGC-1]){
        vett[$0] = ""
    }

    ARGC = ARGC-1
}

{
    if ($1 in vett){
        print $0
        total = total+$3
    } else {
        da_stampare = da_stampare+1
        v[da_stampare] = $0
    }
}

END {

    for(x=1;x<=da_stampare;x++){
        print v[x]
    }

}
