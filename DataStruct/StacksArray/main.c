#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

int main(int argc, char *argv[]){
	Stack stack;
	int top;
	
	initStack(&stack);
	push(&stack, 5);
	push(&stack, 20);
	push(&stack, 10);
	top = peek(stack);
	push(&stack, 3);
	pop(&stack);
	printf("Display: \n");
	display(stack);
	printf("Visualize: \n");
	visualize(stack);
	
//	printf("\n\n");
//	pop(&stack);
//	pop(&stack);
//	pop(&stack);
//	pop(&stack);
//	pop(&stack);
//	display(stack);
	
	return 0;
}
