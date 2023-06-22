#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CircularAQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue queue;
	int choice, i, value;
	bool checker;
	String menuOption[8] = {"Enqueue", "Dequeue", "Is Empty", "Is Full", "Display", "Visualize", "Front", "Remove Item"};
	
	initQueue(&queue);
	
	enqueue(&queue, 10);
	enqueue(&queue, 5);
	enqueue(&queue, 69);
	enqueue(&queue, 89);
	
	displayQueue(queue);
	
	removeItem(&queue, 5);
//	displayQueue(queue);
	
//	do {
//		system("cls");
//		printf("MENU\n");
//		
//		for(i = 0; i < 8; i++){
//			printf("[%d] %s\n", i+1, menuOption[i]);
//		}
//		
//		printf("Enter your choice <0 to EXIT>: ");
//		scanf("%d", &choice);
//				
//		switch(choice){
//			case 1:
//				printf("Enqueue\n");
//				printf("Enter a number: ");
//				scanf("%d", &value);
//				
//				enqueue(&queue, value);
//				break;
//				
//			case 2:
//				printf("Dequeue\n");
//				
//				dequeue(&queue);
//				break;
//				
//			case 3:
//				printf("Is Empty\n");
//				
//				checker = isEmpty(queue);
//				checker ? printf("Queue is empty\n") : printf("Queue is not empty \n");
//				break;
//				
//			case 4:
//				printf("Is Full\n");
//				
//				checker = isFull(queue);
//				checker ? printf("Queue is full\n") : printf("Queue is not yet full \n");
//				break;
//				
//			case 5:
//				printf("Display\n");
//				
//				displayQueue(queue);
//				printf("No Display funciton yet\n");
//				break;
//				
//			case 6:
//				printf("Visualizing...\n");
//				
//				visualize(queue);
//				break;
//				
//			case 7:
//				printf("Front\n");
//				
//				value = front(queue);
//				printf("The first in line: %d\n", value);
//				break;
//				
//			case 8:
//				printf("Remove an item\n");
//				printf("Enter a number: ");
//				scanf("%d", &value);
//				
//				checker = removeItem(&queue, value);
//				checker ? printf("Item has been removed\n") : printf("Item has not been removed\n");
//				break;
//				
//			case 0:
//				printf("Exiting...\n");
//				break;
//				
//			default: 
//				printf("INVALID CHOICE\n");
//		}
//		system("pause");
//	} while(choice != 0); 
//	
//	printf("BYE!!!!!!!!\n\n");
	
	return 0;
}
