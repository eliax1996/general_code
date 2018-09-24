#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"
#include "ST.h"

struct graph {int V; int E; int **adj; ST tab; };
typedef struct graph *Graph;

Graph GRAPHinit(int);
void  GRAPHread(Graph);
void  GRAPHwrite(Graph);
void  GRAPHinsert(Graph G,int n1,int n2,int w);
int*  GRAPHedgesConnectedToANode(Graph g,int node);
void  GRAPHremove(Graph);
void  GRAPHedges(Graph, Edge *);
void  GRAPHshow(Graph);
int   GRAPHpath(Graph);
void  GRAPHbfs(Graph);

#endif
