#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

typedef int Data;

typedef struct node{
	Data data;
	struct node *next;
}StackType, *Stack;

void initStack(Stack *);
bool isEmpty(Stack);
void push(Stack *, int);
void pop(Stack *);
Data peek(Stack);
void display(Stack);
void visualize(Stack);

#endif
