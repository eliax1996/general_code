#ifndef QUEUE_H_DEFINED
#define QUEUE_H_DEFINED

#include "Edge.h"

typedef struct queue *Q;

Q       Qinit(void);
int     Qempty(Q q);
void    Qput (Q q, Edge e);
Edge    Qget(Q q);


#endif
