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

static int figli_morti = 0;
static pid_t f1=0,f2=0;
FILE *fp_readed;
char str[500],str1[500];
int result = 1;

void signal_manager_father(int signal){
    switch (signal) {
        case SIGUSR1:
            printf("\nmessaggio figlio 1");
            kill(f2, SIGUSR1);
            pause();
            break;
            
        case SIGUSR2:
            printf("\nmessaggio figlio 2");
            kill(f1, SIGUSR1);
            pause();
            break;
            
        case SIGCHLD:
            figli_morti++;
            printf("\nfiglio morto, figli morti: %d",figli_morti);
            if (figli_morti < 2)
                pause();
            kill(f1, SIGUSR2);
            kill(f1, SIGUSR2);
            break;
            
        default:
            printf("\nmessaggio di altro tipo");
            break;
    }
}

void signal_manager_child_1(int signal){
    switch (signal) {
        case SIGUSR1:
            result = fscanf(fp_readed, "%s",str);
            printf("%s",str);
            kill(getppid(), SIGUSR1);
            printf("vado in sleep");
            if (result != EOF)
                pause();
            break;
        case SIGUSR2:
            // per garantire che al
            // padre non arrivino 2 SIGCHLD
            // contemporaneamente
            sleep(1);
            
            while(fscanf(fp_readed, "%s",str)!=EOF)
                printf("%s",str);
            break;
    }
}

void signal_manager_child_2(int signal){
    switch (signal) {
        case SIGUSR1:
            result = fscanf(fp_readed, "%s",str1);
            printf("%s",str1);
            kill(getppid(), SIGUSR2);
            printf("vado in sleep");
            if (result != EOF)
                pause();
            break;
        case SIGUSR2:
            // per garantire che al
            // padre non arrivino 2 SIGCHLD
            // contemporaneamente
            sleep(1);
            
            while(fscanf(fp_readed, "%s",str1)!=EOF)
                printf("%s",str1);
            break;
    }
}

int main(int argc, const char * argv[]) {
    signal(SIGUSR1, signal_manager_father);
    signal(SIGUSR2, signal_manager_father);
    signal(SIGCHLD, signal_manager_father);
    signal(SIGINT, signal_manager_father);
    
    if((f1 = fork())>0)f2=fork();
    
    // opera del padre
    if (f1 != 0 && f2 != 0) {
        pause();
    } else {
        // codice comune per i figli
        signal(SIGCHLD, NULL);
        
        // opera del figlio 1
        if (f1==0){
            signal(SIGUSR1, signal_manager_child_1);
            signal(SIGUSR2, signal_manager_child_1);
            fp_readed = fopen("/Volumes/RAM Disk/file1.txt", "r");
            fscanf(fp_readed, "%s",str);
            printf("%s",str);
            kill(getppid(), SIGUSR1);
            pause();
        // opera del figlio 2
        } else {
            signal(SIGUSR1, signal_manager_child_2);
            signal(SIGUSR2, signal_manager_child_2);
            fp_readed = fopen("/Volumes/RAM Disk/file2.txt", "r");
            pause();
            fscanf(fp_readed, "%s",str);
            printf("%s",str1);
            kill(getppid(), SIGUSR2);
            pause();
        }
    }
}
