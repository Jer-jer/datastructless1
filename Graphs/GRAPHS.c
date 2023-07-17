#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "GRAPHS.h"

void initGraph(Dictionary graph){
	
	for(int i = 0; i < MAX; i++){
		strcpy(graph[i].key, "");
	}
	
}
Value initValue(){
	Value newValue;
	
	newValue.count = 0;
	newValue.max = 0;
	
	return newValue;
} 
int hash(String loc, int increment){
	return (toupper(loc[0]) + increment) % MAX;
}
bool addVertex(Dictionary graph, String loc){
	int i = 0, count = 0;
	int key = hash(loc, i);
	
	while(count < MAX && strcmp(graph[key].key, "") != 0){
		key = hash(loc, ++i);
		count++;
	}
	
	if(count != MAX){
		graph[key].value = initValue();
		strcpy(graph[key].key, loc);
	
		return true;
	}
	
	return false;
	
}
bool addEdge(Dictionary graph, String loc1, String loc2);
void displayGraph(Dictionary graph){
	for(int i = 0; i < MAX; i++){
		printf("INDEX: %d KEY: %s\n", i, graph[i].key);
	}
}
