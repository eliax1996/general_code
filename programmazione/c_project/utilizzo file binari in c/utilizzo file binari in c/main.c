//
//  main.c
//  utilizzo file binari in c
//
//  Created by Elia Migliore on 28/10/17.
//  Copyright © 2017 Elia Migliore. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // puntatore di tipo file
    FILE* fp;

    int t,size = sizeof(int),numero_blocchi = 2;

    char modalita[] = "r"; // w ,a , rb, wb, ab ,r+ ,w+ ,a+

    fp = fopen("nome_file.txt",modalita);

    // serve l'indirizzo su cui scrivere
    fscanf(fp, "%d",&t);

    // senza l'indirizzo; unicamente i valori!
    fprintf(fp, "%d",t);

    int BUFFER[200];

    // lettura file binario, legge a partire dal puntatore
    // fornito in ingresso un numero size di byte
    // tante volte quante il numero blocchi e li
    // salva a partire dall'indirizzo di buffer

    // es per leggere 10 interi size dovrà essere sizeof(int)
    // il numero blocchi dovrà essere 10
    // il buffer capiente almeno 10
    // e fp l'indirizzo del file o altro che contiene 10 interi

    int numero_dati_letti = fread(&BUFFER, size, numero_blocchi, fp);

    if (numero_dati_letti < size){
        // per distinguere i due casi si usa ferror() e feof()
        printf("è successo un errore o si è arrivati a fine file!");
    }

    // scrittura file binario
    int numero_dati_scritti = fwrite(&BUFFER,size, numero_blocchi, fp);

    if (numero_dati_scritti < size){
        printf("c'è stato un errore di scrittura file!");
    }

    long int offset_di_spostamento = 10; // byte di spostamento, positivi o negativi!

    long int posizione_attuale_nel_file = ftell(fp);

     // possibili valori di posizione_rispetto_a:
     // SEEK_END = dalla fine del file
     // SEEK_CUR = dal cursore
     // SEEK_SET = dall'inizio del file

    int posizione_rispetto_a = SEEK_SET;

    fseek(fp,offset_di_spostamento,posizione_rispetto_a);


    // guarda poi anche fgetpos() e fsetpos()
    // che supportano file grandi anche 2^64 byte a differenza
    // di ftell() e fseek() che sono limitate dal long a 2^31-1 byte

    // ho raggiunto il terminatore file?
    feof(fp);

    fclose(fp);
}
