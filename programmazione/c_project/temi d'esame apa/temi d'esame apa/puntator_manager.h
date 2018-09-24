//
//  puntator_manager.h
//  temi d'esame apa
//
//  Created by Elia Migliore on 20/11/17.
//  Copyright © 2017 Elia Migliore. All rights reserved.
//

#ifndef puntator_manager_h
#define puntator_manager_h
#define DEFAULT_SIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct puntator_manager_s* PTRM;

// function that create the ram space for the ADT
// the number is the amount of element that you
// think to use, use it only if you know the number
// otherwise put it into a negative or 0 value
PTRM PTRMinit(int size);
// function that add if new and return the id of a char array
int PTRMaddInt(PTRM manager,int number,int check_is_new);
// function that add if new and return the id of a char array
int PTRMaddString(PTRM manager,char string[],int check_is_new);
// function that add the puntator passed by puntator
// please attenction! if you use that ADT and after
// you destroy it, it try to do the free of the
// string!
int PTRMaddAllocatedString(PTRM manager,char* string,int check_is_new);
// function that add if new and return the id of an element char
int PTRMaddChar(PTRM manager,char charapter,int check_is_new);
// function that add if new and return the id of an element float
int PTRMaddFloat(PTRM manager,float number,int check_is_new);
// function to add a custom element (a void*) puntator
int PTRMaddCustomElement(PTRM manager,void* object_puntator,int type_id,int check_is_new);
// function that free the ram and destroy the ADT
void PTRMdestroy(PTRM manager);
// function that return the integer value from the position
int PTRMgetInt(PTRM manager,int position);
// function that return the puntator object value from the position
void* PTRMgetCustomObject(PTRM manager,int position,int id_type);
// function that return the char value from the position
char PTRMgetChar(PTRM manager,int position);
// function that return the string puntator from the position
char* PTRMgetString(PTRM manager,int position);
// function that return the float value from the position
float PTRMgetFloat(PTRM manager,int position);
#endif /* puntator_manager_h */
