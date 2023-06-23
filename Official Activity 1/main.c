#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//#include "MainHeader.h"
#include "Stack.h"
//#include "Queue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	VirtualSpace vs;
	StackList stack;
	bool checker;
	
	initVSpace(&vs);
//	visualize(vs);

	initStack(&stack);
	checker = push(&vs, &stack, addProduct(101, "Milo", 1, 8.00, addDate(31, 12, 2024)));
	checker = push(&vs, &stack, addProduct(101, "Milo", 1, 8.00, addDate(31, 12, 2024)));
	checker = push(&vs, &stack, addProduct(101, "Milo", 1, 8.00, addDate(31, 12, 2024)));
	checker ? printf("Memory inserted\n") : printf("Memory full\n");
	displayStack(&vs, &stack);
	visualize(vs);
	
	return 0;
}
