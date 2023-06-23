#ifndef MAIN_HEADER_H
#define MAIN_HEADER_H

#define MAX 20

typedef char String[50];

typedef struct {
	int date; // Must be 2 digits
	int month; // Must be translated to months (use Array)
	int year; // Must be 4 digits
} Date;

typedef struct {
	int prodID;
	String prodName;
	int prodQty;
	double prodPrice;
	Date prodExp;
} Product;

typedef struct {
	Product items;
	int link;
} Stype;

typedef struct {
	Stype data[MAX];
	int avail;
} VirtualSpace;

typedef int StackList;

typedef struct {
	int front;
	int rear;
} Queue;

void initVSpace(VirtualSpace *vs);
int allocSpace(VirtualSpace *vs); // Include check isFull here for efficiency
void deallocSpace(VirtualSpace *vs, int node);
void visualize(VirtualSpace vs);

Date addDate(int date, int month, int year);
Product addProduct(int id, String name, int qty, double price, Date expry);

#endif
