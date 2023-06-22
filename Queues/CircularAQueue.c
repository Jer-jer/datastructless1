#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CircularAQueue.h"

void initQueue(Queue *q){
	q->front = 7;
	q->rear = 6;
	
	for(int i = 0; i < MAX; i++){
		q->elems[i] = EMPTY;
	}
}

void enqueue(Queue *q, int item){
	if(!isFull(*q)){
		q->rear = (q->rear + 1) % MAX;
		q->elems[q->rear] = item;
	}
}

void dequeue(Queue *q){
	if(!isEmpty(*q)){
		q->elems[q->front] = EMPTY;
		q->front = (q->front + 1) % MAX;
	}
}

int front(Queue q){
	if(!isEmpty(q)){
		return q.elems[q.front];
	}
	
	return EMPTY;
}

bool isFull(Queue q){
	return (q.front + 2) % MAX == q.front;
}

bool isEmpty(Queue q){
	return (q.rear + 1) % MAX == q.front;
}

void displayQueue(Queue q){
	printf("%5s | %5s \n", "INDEX", "VALUE");
	printf("--------------------------\n");
	
	while(!isEmpty(q)){
		int value = front(q), i = q.front;
		
		printf("%5d | ", i);
		
		if(value != EMPTY){
			printf("%5d | ", value);
		}
		
		dequeue(&q);
		i = (i + 1) % MAX;
		printf("\n");
	}
	
	printf("--------------------------\n");
}

void visualize(Queue q){
	printf("%5s | %5s | %s\n", "INDEX", "VALUE", "POSITION");
	printf("--------------------------\n");
	
	for(int i = 0; i < MAX; i++){
		printf("%5d | ", i);
		
		if(q.elems[i] != EMPTY){
			printf("%5d | ", q.elems[i]);
		}else{		
			printf("%5s | ", " ");	
		}
		
		if(i == q.front){
			printf("Front");
		}
		
		if(i == q.rear){
			printf("Rear");
		}
		
		printf("\n");
	}
	printf("--------------------------\n");
}

bool removeItem(Queue *q, int item) {
	Queue tempQ;
	bool checker;
	
	tempQ.front = q->front;
	tempQ.rear = q->rear;
	
	// Stopped here
	for(int o = 0; o < MAX; i++){
		q->elems[o] = EMPTY;
	}
	
	while(!isEmpty(*q)){
		int value = front(tempQ);
		
		dequeue(&(*q));
		
		if(value != item){
			enqueue(&tempQ, value);
		}
		
	}
	
	checker = (q->rear != tempQ.rear) ? true : false;
	*q = tempQ;
	
	displayQueue(tempQ);
	
	return checker;
}
//Queue removeEven(Queue q);
//int doubleTheValue (Queue *q, int value);
