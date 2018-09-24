//
//  es_2_laib_8.c
//  temi d'esame apa
//
//  Created by Elia Migliore on 02/12/17.
//  Copyright © 2017 Elia Migliore. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "puntator_manager.h"
#define FILENAME "file.txt"

int ctoi(char c){
    switch (c) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        default:
            return 9;
    }
}

char number_to_char(int n){
    if (n>9){
        printf("error");
        exit(1);
    }
    return (char)(n+48);
}

char* sequence_to_string(int seq[],int dim_seq){
    char* str = malloc(sizeof(char)*(dim_seq+1));
    int x;
    
    for (x=0;x<dim_seq;x++){
        str[x] = number_to_char(seq[x]);
    }
    
    str[dim_seq] = EOF;
    return str;
}

int main(int argc,char* argv[]){
    
    for(x=0;x<10;x++){
        printf("%c",sequence_to_string(x,0));
    }
    
}
