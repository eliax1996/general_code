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

void signal_manager(int signal){
    
    switch (signal) {
        case SIGCHLD:
            printf("\nmio figlio poteva morire!");
            break;
            
        default:
            printf("\n comando non gestito, torno a dormire");
            pause();
            break;
    }
    
    printf("\nRicevuto il segnale %d\n",signal);
}

void signal_manager_figlio_1(int signal){
    
    switch (signal) {
        case SIGUSR1:
            printf("\nok, inizio a lavorare");
            break;
            
        default:
            printf("\n comando non gestito, torno a dormire");
            pause();
            break;
    }
    
    printf("\nRicevuto il segnale %d\n",signal);
}

int main(int argc, const char * argv[]) {
    signal(SIGCHLD, signal_manager);
    signal(SIGUSR1, signal_manager);
    
    int pid1,pid2;
    
    if ((pid1 = fork()) != 0){
        if((pid2 = fork()) != 0){
            pause();
            pause();
            printf("\npadre terminato\n");
        } else {
            int status;
            // figlio numero 2
            signal(SIGCHLD, signal_manager_figlio_1);
            signal(SIGUSR2, signal_manager_figlio_1);
            signal(SIGUSR1, signal_manager_figlio_1);
            waitpid(pid1, &status, WNOHANG);
            printf("\nora dormo per 5 secondi");
            sleep(5);
            printf("\nsto per morire, addio mondo crudele da figlio 1");
            printf("\nstato figlio:%d",status);
            printf("\nprimo figlio terminato!");
            
        }
    } else {
        // figlio numero 1
        signal(SIGCHLD, NULL);
        signal(SIGUSR1, NULL);
        printf("\nsecondo figlio terminato!");
        return 0;
    }
    
    
}
