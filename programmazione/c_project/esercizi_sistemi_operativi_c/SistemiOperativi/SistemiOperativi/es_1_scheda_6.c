//
//  main.c
//  SistemiOperativi
//
//  Created by Elia Migliore on 05/12/17.
//  Copyright © 2017 Elia Migliore. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0


static int somma = 0;
static int differenza = 0;

void signal_manager(int signal){
    
    switch (signal) {
        case SIGINT:
            exit(EXIT_SUCCESS);
            break;
        
        case SIGUSR1:
            printf("\n la somma vale:%d",somma);
            break;
            
        case SIGUSR2:
            printf("\n la differenza vale:%d",differenza);
            break;
            
        default:
            break;
    }
    
    printf("\nRicevuto il segnale %d\n",signal);
}

int main(int argc, const char * argv[]) {
    
    if (argc != 3)
        exit(EXIT_FAILURE);
    
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    
    somma = x+y;
    differenza = abs(x-y);
    
    signal(SIGINT, signal_manager);
    signal(SIGUSR1, signal_manager);
    signal(SIGUSR2, signal_manager);
    
    while (1) {
        pause();
    }
    
    
    
}
