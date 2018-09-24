//
//  main.c
//  Programmazione Dinamica
//
//  Created by Elia Migliore on 06/12/17.
//  Copyright © 2017 Elia Migliore. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_RECURRENCE 1000


int minimo_numero_monete(int valuta,int monete_cambio[],int monete_cambio_size){
    static int* vettore_soluzioni;
    
    if (vettore_soluzioni==NULL){
        vettore_soluzioni = calloc(MAX_RECURRENCE, sizeof(int));
        
        int x;
        for (x=0;x<monete_cambio_size;x++)
            vettore_soluzioni[monete_cambio[x]] = 1;
    }
    
    if (vettore_soluzioni[valuta])
        return vettore_soluzioni[valuta];
    
    int min_costo = MAX_RECURRENCE*MAX_RECURRENCE;
    int x,temp;
    
    for (x=0;x<monete_cambio_size && monete_cambio[x] <= valuta;x++){
        
        temp = 1+minimo_numero_monete(valuta-monete_cambio[x], monete_cambio, monete_cambio_size);
        
        if (temp < min_costo)
            min_costo = temp;
    }
    
    return min_costo;
}

int main(int argc, const char * argv[]) {
    int monete_cambio[3] = {1,8,12};
    
    printf("\n%d",minimo_numero_monete(31, monete_cambio, 3));
    printf("\n%d",minimo_numero_monete(30, monete_cambio, 3));
    printf("\n%d",minimo_numero_monete(32, monete_cambio, 3));
    printf("\n%d",minimo_numero_monete(36, monete_cambio, 3));
    
}
