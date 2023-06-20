#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

void initStack(Stack *stack){
	if(isEmpty(*stack)) {
		printf("NO INITIALIZE, IT'S NOT EMPTY\n");
	}else {
		stack->top = -1;
	}
}
bool isEmpty(Stack stack){
	return stack.top == -1 ? true : false;
}
// push is insertRear and top contains the index of the top
bool isFull(Stack stack){
	return (stack.top == (MAX - 1)) ? true : false;
}
void push(Stack *stack, Data data){
	if(isFull(*stack)){
		printf("Stack is full\n");
	}else {
		stack->elems[++stack->top] = data;	
	}
}
int peek(Stack stack){
	return stack.elems[stack.top];	
}
// Can just use top as params
void pop(Stack *stack){
	if(isEmpty(*stack)){
		printf("Stack is EMPTY\n");
	}else{
		--stack->top;
	}
}
void display(Stack stack){
	// Utilizing push() and starting from the "last"
	Stack container;
	int holder;
	
	initStack(&container);
	
	while(!isEmpty(stack)){
		push(&container, peek(stack));
		pop(&stack);
	}
	
	while(!isEmpty(container)){
		holder = peek(container);
		printf("Data: %d\n", holder);
		push(&stack, holder);
		pop(&container);
	}
	// Not utilizing push()
//	if(!isEmpty(stack)){
//		while(stack.top != -1){
//			printf("Data: %d\n", peek(stack));
//			pop(&stack);
//		}	
//	}else{
//		printf("Stack is SERIOUSLY empty\n");
//	}

}
void visualize(Stack stack){
	for(int i = 0; i < MAX; i++){
		printf("%d\n", stack.elems[i]);
	}
}
