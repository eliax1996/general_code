#include <stdlib.h>
#include <stdio.h>
#include "ST.h"
#include "Queue.h"
#include "Graph.h"

#define MAX 10
#define FILE_GRAFO "/Volumes/RAM Disk/graph.txt"

int **MATRIXint(int r, int c, int val) {
    int i, j;
    int **t = malloc(r * sizeof(int *));
    for (i=0; i < r; i++)
        t[i] = malloc(c * sizeof(int));
    for (i=0; i < r; i++)
        for (j=0; j < c; j++)
            t[i][j] = val;
    
    return t;
}

Graph GRAPHinit(int V) {
    Graph G = malloc(sizeof *G);
    if (G == NULL)
        return NULL;
    G->V = V;
    G->E = 0;
    G->adj = MATRIXint(V, V, 0);
    G->tab = STinit(V);
    if (G->tab == NULL)
        return NULL;
    return G;
}

void  insertE(Graph G, Edge e) {
    int v = e.v, w = e.w, wt = e.wt;
    
    if (G->adj[v][w] == 0)
        G->E++;
    G->adj[v][w] = wt;
}

int* GRAPHedgesConnectedToANode(Graph g,int node){
    int x = 0;
    int* edges = malloc(sizeof(int)*g->V);
    
    for (x=0;x<g->V;x++){
        if (g->adj[node][x]){
            edges[x] = g->adj[node][x];
        }
        else
            edges[x] = -1;
    }
    
    return edges;
}

void GRAPHread(Graph G) {
    
    FILE *fp = fopen(FILE_GRAFO, "r");
    char v1[MAX],v2[MAX];
    int x,y;
    
    fscanf(fp, "%d",&x);
    
    for(y=0;y<x;y++){
        fscanf(fp, "%s",v1);
        STinsert(G->tab, v1);
    }
    
    while(fscanf(fp, "%s %s %d", v1, v2, &x) == 3) {
        
        int id1 = STsearch(G->tab, v1);
        if (id1 == -1)
            id1 = STinsert(G->tab, v1);
        
        int id2 = STsearch(G->tab, v2);
        if (id2 == -1)
            id2 = STinsert(G->tab, v2);
        
        if (id1 < 0 || id2 < 0)
            continue;
        
        insertE(G, EDGEcreate(id1, id2, x));
    }
    return;
}

void GRAPHwrite(Graph G) {
    int i;
    char name[MAX];
    FILE *fout;
    Edge a[G->E];
    printf("Input file name: ");
    scanf("%s", name);
    fout = fopen(name, "w");
    if (fout == NULL)
        exit(-1);
    GRAPHedges(G, a);
    for (i = 0; i < G->E; i++)
        fprintf(fout, "%s  %s %d\n", STretrieve(G->tab, a[i].v),STretrieve(G->tab, a[i].w), a[i].wt);
    fclose(fout);
    return;
}

void GRAPHinsert(Graph G,int n1,int n2,int w) {
    
    insertE(G, EDGEcreate(n1, n2, w));
    return;
}


void  removeE(Graph G, Edge e) {
    int v = e.v, w = e.w;
    if (G->adj[v][w] != 0)
        G->E--;
    G->adj[v][w] = 0;
}

void GRAPHremove(Graph G) {
    char src[MAX], dst[MAX];
    
    printf("Insert first node = ");
    scanf("%s", src);
    printf("Insert second node = ");
    scanf("%s", dst);
    
    int id1 = STsearch(G->tab, src);
    int id2 = STsearch(G->tab, dst);
    
    if (id1 < 0 || id2 < 0)
        return;
    
    removeE(G, EDGEcreate(id1, id2,G->adj[id1][id2]));
    return;
}

void  GRAPHedges(Graph G, Edge *a) {
    printf("sono in GRAPHedges\n");
    int v, w, E = 0;
    for (v=0; v < G->V; v++)
        for (w=0; w < G->V; w++)
            if (G->adj[v][w] != 0)
                a[E++] = EDGEcreate(v, w, G->adj[v][w]);
    return;
}

void  GRAPHshow(Graph G) {
    int i, j;
    printf("Graph has %d vertices, %d edges \n", G->V, G->E);
    for (i=0; i < G->V; i++) {
        printf("%s:  ", STretrieve(G->tab, i));
        for (j=0; j < G->V; j++)
            if (G->adj[i][j] !=0)
                printf("\t%s %d", STretrieve(G->tab, j), G->adj[i][j]);
        printf("\n");
    }
}


int pathR(Graph G, int v, int w, int *visited) {
    int t;
    if (v == w)
        return 1;
    visited[v] = 1;
    for ( t = 0 ; t < G->V ; t++)
        if (G->adj[v][t] !=0)
            if (visited[t] == 0)
                if (pathR(G, t, w, visited)) {
                    printf("edge (%s, %s) belongs to path \n", STretrieve(G->tab, v), STretrieve(G->tab, t));
                    return 1;
                }
    return 0;
}

int GRAPHpath(Graph G) {
    int t, found, *visited;
    char src[MAX], dst[MAX];
    
    visited = malloc(G->V*sizeof(int));
    for ( t = 0 ; t < G->V ; t++)
        visited[t] = 0;
    
    printf("Insert first node = ");
    scanf("%s", src);
    printf("Insert second node = ");
    scanf("%s", dst);
    
    int id1 = STsearch(G->tab, src);
    int id2 = STsearch(G->tab, dst);
    
    if (id1 < 0 || id2 < 0)
        return 0;
    
    found = pathR(G, id1, id2, visited);
    if (found == 0)
        printf("\n Path not found!\n");
    return found;
}


void bfs(Graph G, Edge e, int *time, int *pre, int *st) {
    int v;
    Q q = Qinit();
    Qput(q, e);
    while (!Qempty(q))
        if (pre[(e = Qget(q)).w] == -1) {
            pre[e.w] = (*time)++;
            st[e.w] = e.v;
            for (v = 0; v < G->V; v++)
                if (G->adj[e.w][v] != 0)
                    if (pre[v] == -1)
                        Qput(q, EDGEcreate(e.w, v, G->adj[e.w][v]));
        }
}

void GRAPHbfs(Graph G) {
    int v, time=0, *pre, *st;
    pre = malloc(G->V*sizeof(int));
    st = malloc(G->V*sizeof(int));
    
    for (v=0; v < G->V; v++) {
        pre[v] = -1;
        st[v] = -1;
    }
    bfs(G, EDGEcreate(0,0,0), &time, pre, st);
    
    printf("\n Resulting BFS tree \n");
    for (v=0; v < G->V; v++)
        if (st[v] != -1)
            printf("%s's parent is: %s \n", STretrieve(G->tab, v), STretrieve(G->tab, st[v]));
}

