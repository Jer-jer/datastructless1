#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#define MAX 3

typedef int Data;

typedef struct {
	Data elems[MAX];
	int top;
}Stack;

void initStack(Stack *stack);
bool isEmpty(Stack stack);
bool isFull(Stack stack);
void push(Stack *stack, Data data);
Data peek(Stack stack);
void pop(Stack *stack);
void display(Stack stack);
void visualize(Stack stack);

#endif
