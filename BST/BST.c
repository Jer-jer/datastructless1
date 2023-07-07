#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "BST_HEADER.h"

// Add element to BST based on product ID
BSTPtr addElement(BSTPtr list, Product item){ // using recursive method
	
	if(isEmpty(list)){
		BSTPtr newNode = malloc(sizeof(NodeType));
	
		newNode->data = item;
		newNode->left = NULL;
		newNode->right = NULL;
		list = newNode;
	}else {
		if(list->data.prodID > item.prodID){
			list->left = addElement(list->left, item);

		}else if(list->data.prodID < item.prodID){
			list->right = addElement(list->right, item);
		}
	}
	
	return list;

}
void insertBST(BSTPtr *list, Product item){ // using iterative method
	BSTPtr *head = list,
	newNode = malloc(sizeof(NodeType));
	
	newNode->data = item;
	newNode->left = NULL;
	newNode->right = NULL;
	
	while(!isEmpty(*head)){
		if((*head)->data.prodID > item.prodID){
			*head = &(*head)->left;
			
		}else if(head->data.prodID < item.prodID){
			*head = &(*head)->right;
		}
	}
	
	*head = newNode;
}
// Delete element in the BST base on the product ID
void removeElement(BSTPtr *list, int prodID); // using iterative method
BSTPtr deleteElement(BSTPtr list, int prodID){ // using recursive method
	if(isEmpty(list)){
		printf("Nothing to delete really");
	}else{
		if(list->data.prodID == prodID){
			BSTPtr holder = list;
			
		}
		if(list->data.prodID > item.prodID && list->left == NULL){
			BSTPtr newNode = malloc(sizeof(NodeType));
	
			newNode->data = item;
			newNode->left = NULL;
			newNode->right = NULL;
			
			list->left = newNode;
		}else if(list->data.prodID > item.prodID && list->left != NULL){
			// Access left sub-tree
			return addElement(list->left, item);
		}else if(list->data.prodID < item.prodID && list->right == NULL){
			BSTPtr newNode = malloc(sizeof(NodeType));
	
			newNode->data = item;
			newNode->left = NULL;
			newNode->right = NULL;
			
			list->right = newNode;
		}else if(list->data.prodID < item.prodID && list->right != NULL){
			// Right sub-tree
			return addElement(list->right, item);
		}
	}
	
	return list
}

// Display BST all in recursive method
void inorderBST(BSTPtr list){
	if(!isEmpty(list)){
		inorderBST(list->left);
		displayProduct(list->data);
		inorderBST(list->right);
	}

}
void preorderBST(BSTPtr list){
	if(!isEmpty(list)){
		displayProduct(list->data);
		preorderBST(list->left);
		preorderBST(list->right);
	}
	
}
void postorderBST(BSTPtr list){
	if(!isEmpty(list)){
		postorderBST(list->left);
		postorderBST(list->right);
		isplayProduct(list->data);
	}
}

// Other functions
BSTPtr newBST(){
	BSTPtr newTree = NULL;
	
	return newTree;
}
void initBST(BSTPtr *list){
	*list = NULL;
}
bool isEmpty(BSTPtr list){
	return list->left == NULL && list->right == NULL;
}
Product createProduct(int id, char *name, int qty, float price){
	Product newProduct;
	
	newProduct.prodID = id;
	strcpy(newProduct.prodName, name);
	newProduct.prodQty = qty;
	newProduct.prodQty = price;
}
// use the following format {<id> | <prodName} replacing the angular brackets with data
void displayProduct(Product prod){
	printf("{%5s %5d | %s\n}", " ", prod.prodID, prod.prodName);
	printf("{%5s %5d | %f\n\n}", " ", prod.prodQty, prod.prodPrice);
}
BSTPtr max(BSTPtr list);
BSTPtr min(BSTPtr list);
bool isMember(BSTPtr list, int prodID);
