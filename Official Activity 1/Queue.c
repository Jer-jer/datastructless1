#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "MainHeader.h"
#include "Queue.h"

void initStack(Queue *q){
	q->front = -1;
	q->rear = -1;
}
bool enqueue(VirtualSpace *vs, Queue *q, Product newProd){
	Queue newNode = allocSpace(vs);
	
	if(newNode == -1) return false;
	
	vs->data[newNode].items = newProd;
	
	if(q->front = -1 && q->rear = -1){
		q->front = q->rear = newNode;
	}else {
		vs->data[q->rear].link = newNode;
		q->rear = newNode;
	}
	
	return true;
}
bool dequeue(VirtualSpace *vs, Queue *q);
Product front(VirtualSpace *vs, Queue q);
