//
//  SimbleTable.h
//  apa_laibs
//
//  Created by Elia Migliore on 23/10/17.
//  Copyright © 2017 Elia Migliore. All rights reserved.
//

#ifndef SimbleTable_h
#define SimbleTable_h

#include <stdio.h>
#include <stdlib.h>

struct my_simble_table_element {
    void* puntator;
};

struct my_simble_table {
    struct my_simble_table_element** elements;
    struct my_simble_table_element** elements_ordered_by_puntator;
    int number;
    int number_allocated;
    int ordered;
};

typedef struct my_simble_table_element* SimbleTableElement;
typedef struct my_simble_table* SimbleTable;

#endif /* SimbleTable_h */
