//
//  main.c
//  esercizi_sistemi_operativi_c
//
//  Created by Elia Migliore on 31/10/17.
//  Copyright © 2017 Elia Migliore. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SIZE 512


int main(int argc, const char * argv[]) {

    int state = 0;

    if (argc != 3){
        printf("errore i parametri devono essere 3!");
        return 1;
    }

    void* buff = malloc(sizeof(char)*BUFF_SIZE);


    int file_in = open(argv[1], O_RDONLY);
    int file_out = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    printf("%s\n", argv[1]);
    printf("%s\n", argv[2]);
    
    /*
    if( file_in == -1 || file_out == -1) {
        perror("errore di apertura file");
        return 1;
    }
     */

    state = read(file_in,buff,BUFF_SIZE);

    while (state != 0 && state != EOF) {
        if (state < 0){
            perror("errore lettura files");
            exit(1);
        } else {
            state = write(file_out, buff, BUFF_SIZE);
        }
        
        print_content((char*)buff,BUFF_SIZE);

        /*
        if (state < 0){
            perror("errore scrittura files");
            exit(1);
        }*/

        state = read(file_in,buff,BUFF_SIZE);
    }
    
    close(file_out);
    close(file_in);


    free(buff);

    return 0;
}









