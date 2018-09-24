//
//  Queque.c
//  apa_laibs
//
//  Created by Elia Migliore on 19/10/17.
//  Copyright © 2017 Elia Migliore. All rights reserved.
//

#include "Queque.h"

/*
 struct my_queque {
     struct my_queque* head;
     struct my_queque* tail;
     void* data;
 }
*/

Queue quequeInit(void* data){
    Queue q = (struct my_queue*) malloc(sizeof(struct my_queue));
    QueueElement element = malloc(sizeof(struct my_queue_element));
    
    element->data = data;
    element->next = NULL;
    element->pre = NULL;
    
    q->head = element;
    q->tail = element;
    
    return q;
}

void quequePush(Queue q,void* data){
    QueueElement element = q->tail;
    QueueElement last = malloc(sizeof(struct my_queue_element));
    
    last->data = data;
    last->next = NULL;
    last->pre = element;
    
    element->next = last;
    q->tail = last;
}

void* quequePop(Queue q){
    QueueElement last = q->tail;
    
    q->tail = q->tail->pre;
    
    if (q->tail == NULL){
        q->head = NULL;
        return NULL;
    } else {
        q->tail->next = NULL;
    }
    
    void* data = last->data;
        
    free(last);
    
    return data;
}

void queueElementDestroy(QueueElement q,void (*function_destroy_element)(void*)){
        if (q != NULL){
            queueElementDestroy(q->next,function_destroy_element);
        
        if (function_destroy_element != NULL)
            function_destroy_element(q->data);
        
        free(q);
    }
}

void queueDestroy(Queue q,void (*function_destroy_element)(void*)){
    queueElementDestroy(q->head,function_destroy_element);
    
    q->head = NULL;
    q->tail = NULL;
    
    free(q);
}

void* queueGetDataAtPosition_r(QueueElement e,int position){
    if (position == 0)
        return e->data;
    
    if (e->next == NULL)
        return NULL;
    
    return queueGetDataAtPosition_r(e->next, position-1);
}

void* queueGetDataAtPosition(Queue q,int position){
    if (position == 0)
        return q->head->data;
    
    return queueGetDataAtPosition_r(q->head, position);
}

// da qui in poi da rivedere

void* queuePopDataAtPosition_r(QueueElement e,int position){
    if (position == 0){
        void* d = e->data;
        QueueElement pre = e->pre;
        e->next->pre = pre;
        pre->next = e->next;
        
        free(e);
        
        return d;
    }
    
    if (e->next == NULL)
    return NULL;
    
    return queueGetDataAtPosition_r(e->next, position-1);
}


void* queuePopDataAtPosition(Queue q,int position){
    if (position == 0){
        QueueElement e = q->head;
        
        if (e->next == NULL){
            void* d = e->data;
            
            queueDestroy(q, NULL);
            
            return d;
        }
        
        q->head = e->next;
        q->head->pre = NULL;
        
        return e->data;
    }
    
    return queuePopDataAtPosition_r(q->head, position);
}















