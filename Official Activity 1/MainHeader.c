#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "MainHeader.h"

void initVSpace(VirtualSpace *vs){
	int lastIndex = MAX - 1;
	
	for(int i = lastIndex; i > -1; i--){
		vs->data[i].items = addProduct(0, "", 0, 0.00, addDate(0, 0, 0));
		vs->data[i].link = i - 1;
	}
	
 	vs->avail = lastIndex;
}
int allocSpace(VirtualSpace *vs){ // Include check isFull here for efficiency
	int retval = vs->avail;
	
	if(retval != -1) {
		vs->avail = vs->data[retval].link;

	}
	
	return retval;	
	
}
void deallocSpace(VirtualSpace *vs, int node){ // Accepts a node that has a next of -1
	vs->data[node].items = addProduct(0, "", 0, 0.00, addDate(0, 0, 0));
	
	vs->data[node].link = vs->avail;
	vs->avail = node;
}
void visualize(VirtualSpace vs){
	printf("%5s | %5s | %5s | %5s\n", "INDEX", "PRODUCT ID", "PRODUCT NAME", "LINK");
	printf("---------------------------------------------------------\n");
	
	for(int i = 0; i < MAX; i++){
		printf("%5d | ", i);
		
		printf("%10d | ", vs.data[i].items.prodID);
		
		(strlen(vs.data[i].items.prodName) != 0 ) ? printf("%12s | ", vs.data[i].items.prodName) : printf("%12s | ", " ");
		
		printf("%5d\n", vs.data[i].link);		
	}
	
	printf("---------------------------------------------------------\n");
	printf("AVAILABLE: %d\n", vs.avail);
	
	printf("\n\n");
}
Date addDate(int date, int month, int year){
	Date newDate = { .date = date, .month = month, .year = year };
	
	return newDate;
}
Product addProduct(int id, String name, int qty, double price, Date expry){
	Product newProduct;
	
	newProduct.prodID = id;
	strcpy(newProduct.prodName, name);
	newProduct.prodQty = qty;
	newProduct.prodExp = expry;
	
	return newProduct;
}

