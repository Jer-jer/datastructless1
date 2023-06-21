#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CursorBased.h"

Student newStudent(int id, String studName, String program, char sex){
	Student s;
	
	s.schoolID = id;
	strcpy(s.studName, studName);
	s.sex = sex;
	strcpy(s.program, program);
	
	return s;
}
VirtualHeap newVirtualHeap(){
	VirtualHeap newHeap;
	
	for(int i = 0; i < MAX; i++){
		newHeap.elems[i].elem = newStudent(0, "", "", ' '); // For representation purposes, so it won't be looped?
		newHeap.elems[i].next = i - 1;
	}
	newHeap.avail = MAX - 1;
	
	return newHeap;
}
int allocSpace(VirtualHeap *vh){
	int retval = vh->avail;
	
	if(retval != -1){
		vh->avail = vh->elems[retval].next;
	}
	
	return retval;
}
void deallocSpace(VirtualHeap *vh, int index){	
	if(index != -1 && index < MAX){
		vh->elems[index].elem = newStudent(0, "", "", ' ');
		vh->elems[index].next = vh->avail;
		vh->avail = index;	
	}
}
void insertFront(List *list, VirtualHeap *vh, Student s){
	List temp = allocSpace(vh);
	
	if(temp != -1){
		vh->elems[temp].elem = s;
		vh->elems[temp].next = *list;
		*list = temp;
	}
}
Student removeStudent(VirtualHeap *vh, List *list, String name){
	int holder, ahead, head = *list;
	
	while(vh->elems[vh->elems[head].next].next != -1 && strcmp(vh->elems[vh->elems[head].next].elem.studName, name)){
		head = vh->elems[head].next;
	}
	
	if(!strcmp(vh->elems[vh->elems[head].next].elem.studName, name)){
		holder = vh->elems[head].next;
		vh->elems[head].next = vh->elems[holder].next;
		vh->elems[holder].next = -1;
		deallocSpace(vh, holder);
	}
	
	return vh->elems[vh->elems[head].next].elem;
}
void displayList(List list, VirtualHeap vh){
	printf("%5s | %30s | %s\n", "INDEX", "ELEMENTS", "NEXT");
	printf("---------------------------------------------\n");
	
	while(list != -1){
		printf("%5d |", list);
		if(!vh.elems[list].elem.schoolID){
			printf("%30s | ", "Empty");	
		}else{
			printf("%4d - %23s | ", vh.elems[list].elem.schoolID, vh.elems[list].elem.studName);
		}
		printf("%d\n", vh.elems[list].next);
		list = vh.elems[list].next;
	}
	
	printf("---------------------------------------------\n");
}
void visualizeHeap(VirtualHeap vh){
	printf("%5s | %30s | %s\n", "INDEX", "ELEMENTS", "NEXT");
	printf("---------------------------------------------\n");
	
	
	
	for(int i = 0; i < MAX; i++){
		printf("%5d |", i);
		if(!vh.elems[i].elem.schoolID){
			printf("%30s | ", "Empty");	
		}else{
			printf("%4d - %23s | ", vh.elems[i].elem.schoolID, vh.elems[i].elem.studName);
		}
		printf("%d\n", vh.elems[i].next);
	}
	
	printf("---------------------------------------------\n");
	printf("AVAILABLE: %d\n\n", vh.avail);
}

