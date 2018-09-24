//
//  main.c
//  tema_desame_grafo
//
//  Created by Elia Migliore on 08/01/18.
//  Copyright © 2018 Elia Migliore. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "ST.h"
#include "Queue.h"

int costo_minimo(Graph G,int vettore_marked[],int actual_node,int destination_node,int numero_nodi,int peso_attuale,int *peso_minimo){
    
    if (peso_attuale > *peso_minimo)
        return 1;
    
    if(actual_node == destination_node){
        *peso_minimo = peso_attuale;
    }
    
    int x;
    
    for(x=0;x<numero_nodi;x++){
        if (!vettore_marked[x]){
            if (G->adj[actual_node][x]){
                vettore_marked[x] = 1;
                costo_minimo(G, vettore_marked, x, destination_node, numero_nodi,peso_attuale+G->adj[actual_node][x],peso_minimo);
                vettore_marked[x] = 0;
            }
        }
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    int numero_nodi = 14;
    Graph G = GRAPHinit(numero_nodi);
    GRAPHread(G);
    
    int x;
    for(x=0;x<numero_nodi;x++){
        printf("edge %d: %s\n",x,STretrieve(G->tab, x));
    }
    
    int* vett = calloc(numero_nodi, sizeof(int));
    
    
    int costo;
    int y;
    int peso_minimo;
    
    
    for(x=0;x<numero_nodi;x++)
        for (y=0; y<numero_nodi; y++) {
            if (x==y) {
                continue;
            }
            peso_minimo=10000;
            costo_minimo(G, vett,x,y,numero_nodi,0,&peso_minimo);
            
            if (peso_minimo == 10000)
                printf("\nimpossibile collegare %s %s",STretrieve(G->tab, x),STretrieve(G->tab, y));
            else
                printf("\ncosto connessione %s con %s: %d\n",STretrieve(G->tab, x),STretrieve(G->tab, y),peso_minimo);
        }
    
    return 0;
}













