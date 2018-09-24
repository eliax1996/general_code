//
//  Graph.h
//  apa_laibs
//
//  Created by Elia Migliore on 21/10/17.
//  Copyright © 2017 Elia Migliore. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <stdio.h>

struct my_graph {
    int number_nodes;
    int number_edges;
    struct my_node* nodes;
    struct my_edge* edges;
};

struct my_edge {
    
    void* data;
    int weight;
};

struct my_node {
    void* data;
    void* adjacencyQueue;
};

typedef struct my_edge* GraphEdge;
typedef struct my_node* GraphNode;










#endif /* Graph_h */
