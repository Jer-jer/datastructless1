#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "MainHeader.h"
#include "Stack.h"

void initStack(StackList *stack){
	*stack = -1;
}
bool push(VirtualSpace *vs, StackList *stack, Product newProd){
	int newNode = allocSpace(vs);
	
	if(newNode == -1) return false;
	
	vs->data[newNode].items = newProd;
	vs->data[newNode].link = *stack;
	*stack = newNode;
	
	return true;
}
bool pop(VirtualSpace *vs, StackList *stack){
	StackList holder = *stack;
	
	if(*stack == -1) return false;
	
	*stack = vs->data[*stack].link;
	vs->data[holder].link = -1;
	deallocSpace(vs, holder);
	
	return true;
}
Product peek(VirtualSpace *vs, StackList stack){
	return vs->data[stack].items;
}
void displayStack(VirtualSpace *vs, StackList *stack){
	StackList tempStack;
	Product prod;
	bool checker;
	
	initStack(&tempStack);
	
	while(*stack != -1){
		prod = peek(vs, *stack);
		
		pop(vs, stack);
		
		push(vs, &tempStack, prod);
	}
	
	printf("%5s | %5s |\n", "PRODUCT ID", "PRODUCT NAME");
	printf("----------------------------\n");
	while(tempStack != -1){
		prod = peek(vs, tempStack);
		
		printf("%10d | ", prod.prodID);
		printf("%12s | \n", prod.prodName);

		
		pop(vs, &tempStack);
		
		push(vs, stack, prod);
	}
	
	printf("----------------------------\n\n");
}
