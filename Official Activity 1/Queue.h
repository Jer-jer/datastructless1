#ifndef STACKS_H
#define STACKS_H

#include "MainHeader.h"

void initStack(Queue *q);
bool enqueue(VirtualSpace *vs, Queue *q, Product newProd);
bool dequeue(VirtualSpace *vs, Queue *q);
Product front(VirtualSpace *vs, Queue q);

//Extra Functions
bool dequeueFirstOccurrence(Queue *q, int prodName, VirtualSpace *vs);


#endif
