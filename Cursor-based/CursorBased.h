#ifndef CURSOR_BASED_H
#define CURSOR_BASED_H

#define MAX 10

typedef char String[20];
typedef int List;

typedef struct{
	int schoolID;
	String studName;
	String program;
	char sex;
} Student;

typedef struct{
	Student elem;
	int next;
} SType;

typedef struct{
	SType elems[MAX];
	int avail;
} VirtualHeap;

Student newStudent(int, String, String, char);
VirtualHeap newVirtualHeap();
int allocSpace(VirtualHeap *);
void deallocSpace(VirtualHeap *, int);
void insertFront(List *, VirtualHeap *, Student);
Student removeStudent(VirtualHeap *, List *, String);
void display(List, VirtualHeap);
void visualizeHeap(VirtualHeap);





#endif
