#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

void initStack(Stack *stack){
	*stack = NULL;
}
bool isEmpty(Stack stack){
	return (!stack) ? true : false;
}
void push(Stack *stack, int data){
	StackType *newStack = malloc(sizeof(StackType));
	
	if(newStack != NULL){
		newStack->data = data;
		newStack->next = NULL;
		
		newStack->next = *stack;
		*stack = newStack;
	}
}
void pop(Stack *stack){
	if(!isEmpty(*stack)){
		StackType *temp = *stack;
		*stack = (*stack)->next;
		free(temp);	
	}

}
Data peek(Stack stack){
	return stack->data;
}
void display(Stack stack){
	StackType *tempStack, *holder;
	
	initStack(&tempStack);
	
	while(!isEmpty(stack)){
		push(&tempStack, stack->data);
		holder = stack;
		stack = stack->next;
		pop(&holder);
	}
	
	
	while(!isEmpty(tempStack)){
		printf("Data: %d\n", peek(tempStack));
		push(&stack, tempStack->data);
		holder = tempStack;
		tempStack = tempStack->next;
		pop(&holder);
	}
}
//void visualize(Stack){
//	
//}
