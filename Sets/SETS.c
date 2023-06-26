#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "SETS.h"

Set newSet() {
	Set newSet;
	for(int i = 0; i < MAX; i++){
		newSet.elems[i] = false;
	}
	
	newSet.count = 0;
	
	return newSet;
}
bool addElement(Set *s, int item){
	if(!s->elems[item]) {
		s->count++;
		s->elems[item] = true;
		return true;
	}
	return false;
}
bool removeElement(Set *s, int item){
	if(s->elems[item]) {
		s->count--;
		s->elems[item] = false;
		return true;
	}
	return false;
}
void displaySet(Set s){
	printf("[");
	for(int i = 0; i < MAX; i++){
		printf("%2d", s.elems[i]);
	}
	printf("%1s]", " ");
	printf("\n");

}
Set unionSet(Set a, Set b){
	Set s = newSet();
	
	for(int i = 0; i < MAX; i++){
		if (a.elems[i] | b.elems[i]) addElement(&s, i);
	}
	
	return s;
}
Set intersectionSet(Set a, Set b){
	Set s = newSet();
	
	for(int i = 0; i < MAX; i++){
		if (a.elems[i] & b.elems[i]) addElement(&s, i);
	}
	
	return s;
}

Set differenceSet(Set a, Set b){
	Set s = newSet();
	
	for(int i = 0; i < MAX; i++){
		if(a.elems[i] == b.elems[i] & a.elems[i] != false) addElement(&s, i);
	}
	
	return s;
}
Set symmetricDiffSet(Set a, Set b){
	Set s = newSet();
	
	for(int i = 0; i < MAX; i++){
		if(a.elems[i] != b.elems[i] & a.elems[i] != false) addElement(&s, i);
	}
	
	return s;
}
int cardinality(Set s){
	int cardinality = 0;
	
	for(int i = 0; i < MAX; i++){
		if(s.elems[i]) cardinality++;
	}
	
	return cardinality;
}
