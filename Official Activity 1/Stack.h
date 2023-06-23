#ifndef STACKS_H
#define STACKS_H

#include "MainHeader.h"

void initStack(StackList *stack);
bool push(VirtualSpace *vs, StackList *stack, Product newProd);
bool pop(VirtualSpace *vs, StackList *stack);
Product peek(VirtualSpace *vs, StackList stack);
void displayStack(VirtualSpace *vs, StackList *stack);


#endif
