#include <stdio.h>
#include <stdlib.h>


int comb(int vett_scelte[],int pos,int vett[],int scelte_fatte,int max_scelte,int vett_size){
    int x;
    
    if (pos >= vett_size && scelte_fatte >= max_scelte){
        // controlla soluzione
        for (x=0;x<scelte_fatte;x++)
            printf("%d",vett[vett_scelte[x]]);
        printf("\n");
        
        return 1;
    }
    
    for (x=pos;x<vett_size;x++){
        vett_scelte[scelte_fatte] = x;
        comb(vett_scelte,x+1,vett,scelte_fatte+1,max_scelte,vett_size);
    }
    
    return 0;
}

int all_solutions(int vett[],int vett_scelte[],int vett_size){
    int x;
    for(x=0;x<vett_size;x++){
        comb(vett_scelte,0,vett,0,x,vett_size);
    }
    return 0;
}

int main(int argc,char* argv[]){
    int *vett = malloc(sizeof(int)*20);
    int *vett2 = malloc(sizeof(int)*20);
    int x;
    
    for(x=0;x<20;x++)
        vett[x] = x;
    
    all_solutions(vett,vett2 ,7);
}










