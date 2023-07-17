#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "GRAPHS.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Dictionary newGraph;
	
	initGraph(newGraph);
	
	addVertex(newGraph, "Tokyo");
	
	displayGraph(newGraph);
	
	return 0;
}
