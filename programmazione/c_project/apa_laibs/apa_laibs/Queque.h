//
//  Queque.h
//  apa_laibs
//
//  Created by Elia Migliore on 19/10/17.
//  Copyright © 2017 Elia Migliore. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include <stdlib.h>

// Data definition

struct my_queue {
    struct my_queue_element* head;
    struct my_queue_element* tail;
};

struct my_queue_element {
    struct my_queue_element* pre;
    struct my_queue_element* next;
    void* data;
};

typedef struct my_queue* Queue;
typedef struct my_queue_element* QueueElement;

// Method's

Queue queueInit(void* first_data);
void queueDestroy(Queue q,void (*function_destroy_element)(void*));
void* queueGetDataAtPosition(Queue q,int position);
void queuePush(Queue q,void* data);
void* queuePop(Queue q);


#endif /* Queue_h */
