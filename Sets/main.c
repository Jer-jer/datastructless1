#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "SETS.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Set mySet = newSet(), theirSet = newSet(), s = newSet();
	
	addElement(&mySet, 5);
	addElement(&mySet, 10);
	addElement(&mySet, 19);
	addElement(&mySet, 0);
	addElement(&mySet, 1);
	addElement(&mySet, 15);
	displaySet(mySet);
	addElement(&theirSet, 7);
	addElement(&theirSet, 5);
	addElement(&theirSet, 15);
	addElement(&theirSet, 13);
	addElement(&theirSet, 4);
	addElement(&theirSet, 8);
	addElement(&theirSet, 2);
	displaySet(theirSet);
	
	s = unionSet(mySet, theirSet);
	unionSet(mySet, theirSet);
	displaySet(s);
	
	s = intersectionSet(mySet, theirSet);
	unionSet(mySet, theirSet);
	displaySet(s);
	
	s = differenceSet(mySet, theirSet);
	unionSet(mySet, theirSet);
	displaySet(s);
	
	s = symmetricDiffSet(mySet, theirSet);
	unionSet(mySet, theirSet);
	displaySet(s);
	
	printf("Cardinality of Set mySet: %d\n", cardinality(mySet));
	printf("Cardinality of Set theirSet: %d\n", cardinality(theirSet));
	
	return 0;
}
