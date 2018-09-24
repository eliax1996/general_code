//
//  main.c
//  temi d'esame apa
//
//  Created by Elia Migliore on 20/11/17.
//  Copyright © 2017 Elia Migliore. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define FILE_NEMICI "/Volumes/RAM Disk/nem.txt"
#define FILE_FAMIGLIE "/Volumes/RAM Disk/fam.txt"
#define FILE_KOALA "/Volumes/RAM Disk/hab.txt"


void leggi_koala(int *num_koala,int*** viv_koala,int** vett_dim_vivibilita,int *num_alberi){
    FILE* fp;
    int** vett_vivibilita_koala;
    *num_alberi = -1;
    printf("%s",FILE_KOALA);
    fp = fopen(FILE_KOALA, "r");
    
    fscanf(fp,"%d", num_koala);
    int x,num_alberi_vivibili,y,k;
    vett_vivibilita_koala = (int**) malloc(*num_koala*sizeof(int*));
    *vett_dim_vivibilita = (int*) malloc(sizeof(int)* *num_koala);
    
    
    for(x=0;x<*num_koala;x++){
        fscanf(fp, "%d",&num_alberi_vivibili);
        printf("leggo nuovo koala");
        vett_vivibilita_koala[x] = malloc(sizeof(int)*num_alberi_vivibili);
        (*vett_dim_vivibilita)[x] = num_alberi_vivibili;
        
        for (y=0;y<num_alberi_vivibili;y++){
            fscanf(fp, "%d",&k);
            
            if (k>*num_alberi)
                *num_alberi = k;
            
            vett_vivibilita_koala[x][y] = k;
            printf("\nil koala %d puo vivere %d",y,k);
        }
        
    }
    
    *viv_koala = vett_vivibilita_koala;
    *num_alberi = *num_alberi+1;
}

void leggi_famiglie(int *num_famiglie,int*** fam_koala,int** vett_dim_famiglie){
    int** vett_famiglie_koala;
    FILE* fp;
    fp = fopen(FILE_FAMIGLIE, "r");
    
    fscanf(fp,"%d", num_famiglie);
    int x,d_fam,y,k;
    
    vett_famiglie_koala = malloc(sizeof(int*)* *num_famiglie);
    *vett_dim_famiglie = malloc(sizeof(int)* *num_famiglie);
    
    for (x=0;x<*num_famiglie;x++){
        fscanf(fp, "%d",&d_fam);
        (*vett_dim_famiglie)[x] = d_fam;
        vett_famiglie_koala[x] = malloc(sizeof(int)*d_fam);
        for (y=0;y<d_fam;y++){
            fscanf(fp,"%d", &k);
            vett_famiglie_koala[x][y] = k;
        }
    }
    
    *fam_koala = vett_famiglie_koala;
}

void leggi_incompatibilita(int** vett_incompatibilita){
    FILE* fp;
    fp = fopen(FILE_NEMICI, "r");
    int fam1,fam2;
    
    while (!feof(fp)) {
        fscanf(fp, "%d %d",&fam1,&fam2);
        vett_incompatibilita[fam1][fam2] = 1;
        vett_incompatibilita[fam2][fam1] = 1;
    }
    
}

int vive_albero(int **vett_vivibilita_koala,int albero,int* vett_dim_vivibilita,int koala){
    int x;
    int vive = 0;
    
    for (x=0;x<vett_dim_vivibilita[koala];x++){
        if (vett_vivibilita_koala[koala][x] == albero)
            vive = 1;
    }
    
    return vive;
    
}

int famiglia_koala(int k,int** vett_famiglie_koala,int* vett_dim_koala,int num_famiglie_koala){
    int x,y,tr=-1;
    
    for (x=0;x<num_famiglie_koala&&tr==-1;x++)
        for (y=0;y<vett_dim_koala[x]&&tr==-1;y++){
            if (vett_famiglie_koala[x][y]==k)
                tr = x;
        }
    
    return tr;
}

int combinazioni(int **vett_incompatibilita,int* vett_dim_vivibilita,int** vett_vivibilita_koala,int** vett_famiglie_koala,int* vett_dim_famiglie,int c,int numero_koala,int pos,int* vett_scelte,int* vett_num_per_albero,int num_famiglie_koala){
    int x;
    int sol = 0;
    
    if (pos >= numero_koala){
        
        int f1,f2,y,valida = 1;
        for(x=0;x<numero_koala;x++)
            for (y=x;y<numero_koala;y++){
                if (vett_scelte[x] == vett_scelte[y]){
                    f1 = famiglia_koala(x,vett_famiglie_koala,vett_dim_famiglie,num_famiglie_koala);
                    f2 = famiglia_koala(y,vett_famiglie_koala,vett_dim_famiglie,num_famiglie_koala);
                    
                    if (f1==-1 || f2==-1){
                        printf("errore inspettato!");
                        exit(1);
                    }
                    
                    if (vett_incompatibilita[f1][f2] == 1)
                        valida = 0;
                }
            }
        
        if (valida){
            printf("\nsoluzione valida trovata:");
            for (x=0;x<numero_koala;x++)
                printf("%d",vett_scelte[x]);
        }
        return 0;
    }
    
    for (x=0;x<c;x++){
        // se il koala puo vivere qui allora lo metto altrimenti provo
        // direttamente un altro insieme
        if (vett_num_per_albero[x] && vive_albero(vett_vivibilita_koala, x,vett_dim_vivibilita,pos)){
            vett_scelte[pos] = x;
            vett_num_per_albero[x]--;
            sol = combinazioni(vett_incompatibilita, vett_dim_vivibilita, vett_vivibilita_koala, vett_famiglie_koala, vett_dim_famiglie, c,numero_koala, pos+1,vett_scelte,vett_num_per_albero,num_famiglie_koala);
            vett_num_per_albero[x]++;
            if (sol > 0)
                return sol;
        }
    }
    return 0;
}

int main(int argc,char* argv[]){
    int x,y;
    int num_koala_albero;
    int num_famiglie;
    int num_koala;
    int numero_alberi;
    int** vett_vivibilita_koala = NULL;
    int* vett_dim_vivibilita = NULL;
    int** vett_famiglie_koala = NULL;
    int* vett_dim_famiglie = NULL;
    int** vett_incompatibilita;
    
    leggi_koala(&num_koala, &vett_vivibilita_koala, &vett_dim_vivibilita,&numero_alberi);
    leggi_famiglie(&num_famiglie, &vett_famiglie_koala, &vett_dim_famiglie);
    
    vett_incompatibilita = malloc(sizeof(int*)*num_famiglie);
    
    for (x=0;x<num_famiglie;x++){
        vett_incompatibilita[x] = malloc(sizeof(int));
        for (y=0;y<num_famiglie;y++){
            vett_incompatibilita[x][y] = -1;
        }
    }
    
    leggi_incompatibilita(vett_incompatibilita);
    
    num_koala_albero = 5;//atoi(argv[1]);
    int* vett_scelte = calloc(num_koala,sizeof(int));
    int* vett_gruppi = malloc(sizeof(int)*numero_alberi);
    
    for(x=0;x<numero_alberi;x++)
        vett_gruppi[x] = num_koala_albero;
    
    int sol_tro = 0;
    for(x=1;x<=numero_alberi;x++){ // x=1 soluzione banale
        printf("\n\n\n\n\nsoluzioni con %d alberi:",x);
        sol_tro = combinazioni(vett_incompatibilita,vett_dim_vivibilita,vett_vivibilita_koala,vett_famiglie_koala,vett_dim_famiglie,x,num_koala,0,vett_scelte,vett_gruppi,num_famiglie);
        printf("\n\n\n\n");
    }
    
}
