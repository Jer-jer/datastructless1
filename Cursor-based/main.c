#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CursorBased.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	VirtualHeap myHeap = newVirtualHeap();
	List myList = -1;
	Student s;
	
//	displayList(myList, myHeap);
//	visualizeHeap(myHeap);
	
	insertFront(&myList, &myHeap, newStudent(101, "Jonathan", "BS IT", 'm'));
	insertFront(&myList, &myHeap, newStudent(105, "Sebastian", "BS CS", 'm'));
	insertFront(&myList, &myHeap, newStudent(110, "James", "BS CS", 'm'));
	insertFront(&myList, &myHeap, newStudent(115, "Janine", "BS IS", 'f'));
//	displayList(myList, myHeap);
	
	s = removeStudent(&myHeap, &myList, "James");
//	s = removeStudent(&myHeap, &myList, "Jonathan");
//	s = removeStudent(&myHeap, &myList, "Sebastian");
//	s = removeStudent(&myHeap, &myList, "Janine");
	displayList(myList, myHeap);
	visualizeHeap(myHeap);
	
	return 0;
}
