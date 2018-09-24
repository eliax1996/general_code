//
//  SimbleTable.c
//  apa_laibs
//
//  Created by Elia Migliore on 23/10/17.
//  Copyright © 2017 Elia Migliore. All rights reserved.
//

#include "SimbleTable.h"

SimbleTable simbleTableInit(){
    SimbleTable st = malloc(sizeof(struct my_simble_table));
    
    st->number = 50;
    st->number_allocated = 0;
    st->elements = malloc(sizeof(struct my_simble_table_element));
    
    return st;
}

void* simbleTableReallocIfNeeded(SimbleTable st){
    if (st->number_allocated >= st->number-1){
        int a = st->number*2;
        st->number = a;
        realloc(st->elements_ordered_by_puntator, sizeof(struct my_simble_table_element));
        return realloc(st->elements, sizeof(struct my_simble_table_element));
    }
    
    return NULL;
}

int simbleTableAddElement(SimbleTable st,void* puntator){
    simbleTableReallocIfNeeded(st);
    SimbleTableElement element = malloc(sizeof(struct my_simble_table_element));
    
    st->elements[st->number_allocated] = element;
    st->elements_ordered_by_puntator[st->number_allocated] = element;
    
    element->puntator = puntator;
    
    st->ordered = 0;
    
    int r = st->number_allocated;
    st->number_allocated++;
    
    return r;
}

void simbleTableOrder(SimbleTableElement* vector){
    
}


int simbleTableBinarySearch(void* puntator,SimbleTableElement* vector,int size,int position){
    
    if (vector[position]->puntator == puntator)
        return position;
    
    int next = (size - position)/2;
    
    if (vector[position]->puntator > puntator){
        
    } else {
        
    }
    
}

int simbleTableAddElementIfNotExist(SimbleTable st,void* puntator){
    
    if (!st->ordered){
        simbleTableOrder(st->elements_ordered_by_puntator);
        st->ordered = 1;
    }
    
    return simbleTableBinarySearch(puntator,st->elements_ordered_by_puntator,st->number_allocated,0);
}












