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

int fact(int n){
    if (n <= 1)
        return 1;
    
    if (n > 50)
        return (fact(50) + fact(50) + fact(50))/3;
    
    return fact(n-1)+fact(n-2);
}

static int dati_scritti = 0;


int main(int argc, const char * argv[]) {
    int pipe_address[2];
    
    pipe(pipe_address);
    printf("\nindirizzo pipe lettura: %d",pipe_address[0]);
    printf("\nindirizzo pipe lettura: %d",pipe_address[1]);
    
    pid_t pid_figlio = fork();
    
    if (pid_figlio){
        close(pipe_address[0]);
        
        int x,y,fatt[5];
        
        for(y=0;y<150;y++){
            for (x=0;x<5;x++)
                fatt[x] = fact(x+5*y);
            
            write(pipe_address[1], &fatt, sizeof(int)*5);
            dati_scritti++;
            printf("\nscritti 5 dati %d\n",dati_scritti);
        }
        
    } else {
        close(pipe_address[1]);
        int x,y;
        int fatt[6];
        
        for (x=0;x<150;x++){
            read(pipe_address[0], fatt, sizeof(int)*5);
            for (y=0;y<5;y++){
                printf("\nil fattoriale di %d e': %d",x,fatt[y]);
            }
            dati_scritti-=5;
            printf("\nletti 5 dati\n");
        }
        
    }
    
    
}
