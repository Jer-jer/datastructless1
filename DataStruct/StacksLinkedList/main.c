#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Stack top;
	
	initStack(&top);
	push(&top, 5);
	pop(&top);
	display(top);
	
	return 0;
}
