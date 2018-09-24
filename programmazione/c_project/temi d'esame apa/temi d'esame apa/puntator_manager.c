//
//  puntator_manager.c
//  temi d'esame apa
//
//  Created by Elia Migliore on 20/11/17.
//  Copyright © 2017 Elia Migliore. All rights reserved.
//


// funzioni ancora da inserire appena ho tempo:
// binarize() --> rende binaria la ricerca per puntatori
// per mezzo di una struttura per ogni dato primitivo e per
// ogni categoria di ogni dato custom
// es:
//  struct bin {
//      custom_data_type;
//      int vector_position_ordered;
//      order_manteined; // bool value if 0 is ordered, integer value
//                       // from that value the vector is not ordered
//   }
// binaraze(enum type) // esegue la ricerca binaria solo tra
//                    // il tipo primitivo scelto
// binaraze_custom(int id_type) // esegue la ricerca binaria
// solo tra il custom type scelto
// eventuali aggiunte in futuro:
// removeElementByPuntator()
// removeElementByID()
// searchInt() inizia un nuovo inserimento con check_data a true
// searchFloat()
// searchDouble()
// searchString()
// searchObject()
// seachChar()

#include "puntator_manager.h"

enum type {integer,charapter,stringa,float_number,other};

struct puntator_manager_s {
    int number_of_objects;
    int object_used;
    void** objects;
    enum type *objects_type;
};

struct puntator_standard_data {
    void* object;
};

// aggiungere funzione di cmp
// per fare in modo che sei tu a definire
// quando un oggetto è diverso e quindi
// deve essere allocato
struct puntator_custom_data {
    void* object;
    int id_type; // per differenziare differenti elementi custom: struct studente e struct docente (sono diversi diverse funzioni di paragone)
};

typedef struct puntator_standard_data* PTRMstandard;
typedef struct puntator_custom_data* PTRMcustom;


int searchIntData(PTRM manager,enum type data_type,int data_cmp){
    int x;
    void* data;
    
    for (x=0;x<manager->object_used;x++){
        if (manager->objects_type[x] == data_type){
            data = ((PTRMstandard)manager->objects[x])->object;
            
            if (*(int*)data == data_cmp)
                return x;
        }
    }
    
    return -1;
}

int searchFloatData(PTRM manager,enum type data_type,float data_cmp){
    int x;
    void* data;
    
    for (x=0;x<manager->object_used;x++){
        if (manager->objects_type[x] == data_type){
            data = ((PTRMstandard)manager->objects[x])->object;
            
            if (*(float*)data == data_cmp)
                return x;
        }
    }
    
    return -1;
}

int searchCharData(PTRM manager,enum type data_type,char data_cmp){
    int x;
    void* data;
    
    for (x=0;x<manager->object_used;x++){
        if (manager->objects_type[x] == data_type){
            data = ((PTRMstandard)manager->objects[x])->object;
            
            if (*(char*)data == data_cmp)
                return x;
        }
    }
    
    return -1;
}

int searchStringData(PTRM manager,enum type data_type,char* data_cmp){
    int x;
    void* data;
    
    for (x=0;x<manager->object_used;x++){
        if (manager->objects_type[x] == data_type){
            data = ((PTRMstandard)manager->objects[x])->object;
            
            // // only if the string are che same
            if (strcmp((char*)data,data_cmp)==0)
                return x;
        }
    }
    
    return -1;
}

int searchStringData_puntator(PTRM manager,enum type data_type,char* data_cmp){
    int x;
    void* data;
    
    for (x=0;x<manager->object_used;x++){
        if (manager->objects_type[x] == data_type){
            data = ((PTRMstandard)manager->objects[x])->object;
            
            if ((char*)data == data_cmp)
                return x;
        }
    }
    
    return -1;
}

// !TODO: TEST THE FUNCTION!
int searchData_custom(PTRM manager,int id_type,void* data_cmp){
    int x;
    for (x=0;x<manager->object_used;x++){
        if (manager->objects_type[x] == other){
            PTRMcustom data_structure = ((PTRMcustom)manager->objects[x]);
            if (data_structure->id_type == id_type){
                if (data_structure->object == data_cmp)
                    return x;
            }
        }
    }
    
    return -1;
}

// function that instantiate in memory
// the size for the puntator
PTRM PTRMinit(int size){
    struct puntator_manager_s* t; 
    t = malloc(sizeof(struct puntator_manager_s));
    
    if (t == NULL){
        fprintf(stderr, "\nError, cannot instantiate puntator_manager PTRM, line 21 puntator_manager.c");
        exit(1);
    }
    
    t->object_used = 0;
    
    if (size > DEFAULT_SIZE){
        t->number_of_objects = size;
    } else {
        t->number_of_objects = DEFAULT_SIZE;
    }
    
    t->objects = (void*) malloc(sizeof(void*)*t->number_of_objects);
    t->objects_type = malloc(sizeof(enum type)*t->number_of_objects);
    
    if (t->objects == NULL || t->objects_type == NULL){
        fprintf(stderr, "\nError, cannot instantiate integer puntator in puntator_manager PTRM, line 51-52 puntator_manager.c");
        exit(1);
    }
    
    return t;
}

void verifySpace(PTRM manager){
    if (manager->number_of_objects > manager->object_used)
        return;
    
    manager->number_of_objects = 2*manager->number_of_objects;
    manager->objects = realloc(manager->objects, sizeof(void*)*manager->number_of_objects);
    manager->objects_type = realloc(manager->objects_type, sizeof(enum type)*manager->number_of_objects);
    
    if (manager->objects == NULL || manager->objects_type == NULL){
        fprintf(stderr, "\nError, cannot increment size integer or enum puntators in puntator_manager PTRM, line 65-66 puntator_manager.c");
        exit(1);
    }
    
}

// check_is_new if true check in all the data if the data inserted
// is new or not, if is not new return the puntator
int PTRMaddCustomElement(PTRM manager,void* object_puntator,int type_id,int check_is_new){
    verifySpace(manager);
    
    if (check_is_new){
        int found = searchData_custom(manager, type_id, object_puntator);
        
        if (found >= 0)
            return found;
    }
    
    PTRMcustom data = malloc(sizeof(struct puntator_custom_data));
    
    if (object_puntator == NULL || data == NULL){
        fprintf(stderr, "\nError, cannot instantiate general puntator or structure containing custom data in puntator_manager PTRM, line %d-%d puntator_manager.c",__LINE__-3,__LINE__-2);
        exit(1);
    }
    
    data->object = object_puntator;
    data->id_type = type_id;
    
    
    
    manager->objects[manager->object_used] = data;
    manager->objects_type[manager->object_used] = other;
    manager->object_used++;
    
    return manager->object_used-1;
}

int PTRMaddInt(PTRM manager,int number,int check_is_new){
    verifySpace(manager);
    
    if (check_is_new){
        int found = searchIntData(manager, integer, number);
        
        if (found >= 0)
            return found;
    }
    
    
    int* p = malloc(sizeof(int));
    PTRMstandard data = malloc(sizeof(struct puntator_standard_data));
    
    if (p == NULL || data == NULL){
        fprintf(stderr, "\nError, cannot instantiate integer in puntator_manager PTRM, line 79-80 puntator_manager.c");
        exit(1);
    }
    
    *p = number;
    data->object = p;
    
    manager->objects[manager->object_used] = data;
    manager->objects_type[manager->object_used] = integer;
    manager->object_used++;
    
    return manager->object_used-1;
}

int PTRMaddString(PTRM manager,char string[],int check_is_new){
    verifySpace(manager);
    
    if (check_is_new){
        int found = searchStringData(manager, stringa, string);
        
        if (found >= 0)
            return found;
    }
    
    char* stringa_d = strdup(string);
    PTRMstandard data = malloc(sizeof(struct puntator_standard_data));
    
    if (data == NULL){
        fprintf(stderr, "\nError, cannot instantiate data container in puntator_manager PTRM, line 99-100 puntator_manager.c");
        exit(1);
    }
    
    data->object = stringa_d;
    manager->objects[manager->object_used] = data;
    manager->objects_type[manager->object_used] = stringa;
    manager->object_used++;
    
    return manager->object_used-1;
}

// please attenction! if you use that ADT and after
// you destroy it, it try to do the free of the
// string!
int PTRMaddAllocatedString(PTRM manager,char* string,int check_is_new){
    verifySpace(manager);
    
    if (check_is_new){
        int found = searchStringData_puntator(manager, stringa, string);
        
        if (found >= 0)
            return found;
    }
    
    PTRMstandard data = malloc(sizeof(struct puntator_standard_data));
    
    if (data == NULL){
        fprintf(stderr, "\nError, cannot instantiate data container in puntator_manager PTRM, line 120 puntator_manager.c");
        exit(1);
    }
    
    data->object = string;
    manager->objects[manager->object_used] = data;
    manager->objects_type[manager->object_used] = stringa;
    manager->object_used++;
    
    return manager->object_used-1;
}

int PTRMaddChar(PTRM manager,char charapter_d,int check_is_new){
    verifySpace(manager);
    
    if (check_is_new){
        int found = searchCharData(manager, charapter, charapter_d);
        
        if (found >= 0)
            return found;
    }
    
    char* p = malloc(sizeof(char));
    PTRMstandard data = malloc(sizeof(struct puntator_standard_data));
    
    if (p == NULL || data == NULL){
        fprintf(stderr, "\nError, cannot instantiate char in puntator_manager PTRM, line 98 puntator_manager.c");
        exit(1);
    }
    
    *p = charapter_d;
    
    data->object = p;
    manager->objects[manager->object_used] = data;
    manager->objects_type[manager->object_used] = charapter;
    manager->object_used++;
    
    return manager->object_used-1;
}

int PTRMaddFloat(PTRM manager,float number,int check_is_new){
    verifySpace(manager);
    
    if (check_is_new){
        int found = searchFloatData(manager, float_number, number);
        
        if (found >= 0)
            return found;
    }
    
    float* p = malloc(sizeof(float));
    PTRMstandard data = malloc(sizeof(struct puntator_standard_data));
    
    if (p == NULL || data == NULL){
        fprintf(stderr, "\nError, cannot instantiate float in puntator_manager PTRM, line 103 puntator_manager.c");
        exit(1);
    }
    
    *p = number;
    
    data->object = p;
    manager->objects_type[manager->object_used] = float_number;
    manager->objects[manager->object_used] = data;
    manager->object_used++;
    
    return manager->object_used-1;
}

int PTRMgetInt(PTRM manager,int position){
    
    if (position < 0 || manager->object_used-1 < position){
        printf("Error position value");
        exit(1);
    }
    
    if (manager->objects_type[position] != integer){
        fprintf(stderr, "Error request int for non int value");
        exit(1);
    }
    
    return (*(int*) ((PTRMstandard)manager->objects[position])->object);
}

float PTRMgetFloat(PTRM manager,int position){
    
    if (position < 0 || manager->object_used-1 < position){
        printf("Error position value");
        exit(1);
    }
    
    if (manager->objects_type[position] != float_number){
        fprintf(stderr, "Error request float for non float value");
        exit(1);
    }
    
    return (*(float*) ((PTRMstandard)manager->objects[position])->object);
}

char* PTRMgetString(PTRM manager,int position){
    
    if (position < 0 || manager->object_used-1 < position){
        printf("Error position value");
        exit(1);
    }
    
    if (manager->objects_type[position] != stringa){
        fprintf(stderr, "Error request string for non string value");
        exit(1);
    }
    
    return (char*) ((PTRMstandard)manager->objects[position])->object;
}

char PTRMgetChar(PTRM manager,int position){
    
    if (position < 0 || manager->object_used-1 < position){
        printf("Error position value");
        exit(1);
    }
    if (manager->objects_type[position] != charapter){
        fprintf(stderr, "Error request char for non char value");
        exit(1);
    }
    
    return (*(char*) ((PTRMstandard)manager->objects[position])->object);
}

void* PTRMgetCustomObject(PTRM manager,int position,int id_type){
    
    if (position < 0 || manager->object_used-1 < position){
        printf("Error position value");
        exit(1);
    }
    
    if (manager->objects_type[position] != other){
        fprintf(stderr, "Error request object for non object value");
        exit(1);
    }
    
    if (((PTRMcustom)manager->objects[position])->id_type != id_type){
        fprintf(stderr, "Error request %d object type, but object type was %d",id_type,((PTRMcustom)manager->objects[position])->id_type);
        exit(1);
    }
    
    return ((PTRMcustom)manager->objects[position])->object;
}

void PTRMdestroy(PTRM manager){
    int x;
    
    for (x=0;x<manager->object_used-1;x++){
        free(manager->objects[x]);
    }
    
    free(manager);
}










