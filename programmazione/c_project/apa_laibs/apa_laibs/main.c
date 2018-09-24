//
//  main.c
//  apa_laibs
//
//  Created by Elia Migliore on 19/10/17.
//  Copyright © 2017 Elia Migliore. All rights reserved.
//

/*
 
 // debug stop or condictional stop
 #ifdef DEBUG
     if (foo)
     stop();
 #endif
 
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Queque.h"
#define DEBUG 1

int random_number(int max){
    return rand()%max;
}

void stampa_insieme(int array[],int *finito){
    int x,size_insieme = random_number(6);
    
    if (size_insieme == 0)
        return;
    
    int n;
    for (x=0;x<size_insieme;x++){
        n = random_number(15);
        printf("%d ",n);
        array[n] = 1;
    }
    
    int all = 1;
    
    for (x=0;x<15;x++)
        if (!array[x])
            all = 0;
    
    *finito = all;
    
    printf("\n");
    
}

int genera_insiemi(){
    
    srand((int)time(NULL));
    
    int array[15],x;
    
    for(x = 0;x < 15;x++)
        array[x] = 0;
    
    int finito = 0;
    
    while (!finito) {
        stampa_insieme(array, &finito);
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
}

















