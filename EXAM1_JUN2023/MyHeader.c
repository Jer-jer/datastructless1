#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyHeader.h"

int allocSpace(VSpace *vs) {
	int loc = vs->avail;
	
	if(loc != -1) {
		vs->avail = vs->data[loc].pos;
	}
	
	return loc;
}

void freeSpace(VSpace *vs, int loc) {
	if(loc != -1 && loc < MAX_SPACE) {
		vs->data[loc].pos = vs->avail;
		vs->avail = loc;
	}
}

void displayPokemon(Pokemon p) {
	printf("{%d | %s - ", p.pokeID, p.pokeName);
	displayType(p.pokeType.mainType);
	printf("}\n");
}

void displayPokemonDetail(Pokemon p) {
	printf("%10s: %d\n", "ID", p.pokeID);
	printf("%10s: %s\n", "Name", p.pokeName);
	printf("");
}

void displayType(int type) {
	int i;
	String typeNames[18] = {"Normal", "Fire", "Water", "Grass", 
					"Electric", "Ice", "Fighting", "Poison",
					"Ground", "Flying", "Psychic", "Bug",
					"Rock", "Ghost", "Dark", "Dragon",
					"Steel", "Fairy"};
	
	printf("[");
	// to do code logic here
	unsigned int mask = 1;
	int counter = 0;
	while(counter < 18){
		if(type & mask){
			printf("%s ", typeNames[counter]);
		}
		mask <<= 1;
		counter++;
	}

	printf("] ");
}

VSpace newVSpace() {
	VSpace vs;
	int i;
	
	for(i = MAX_SPACE - 1; i >= 0; --i) {
		vs.data[i].dataDetail.pokeID = -1;	// will tag it as empty
		vs.data[i].pos = i-1;
	}
	vs.avail = MAX_SPACE - 1;
	
	return vs;
}


Tile newTile() {
	Tile t;
	
	t.start = 1;
	t.end = 2;
	
	return t;
}

Deck newDeck() {
	Deck d;
	
	d.stack = newStackList();
	d.space = newVSpace();
	
	return d;
}

StackPokemonList newDiscard(int size) {
	StackPokemonList list;
	
	list.max = size;
	list.count = 0;
	list.pokeList = malloc(sizeof(Pokemon) * list.max);
	
	return list;
}

StackList newStackList() {
	return -1;	
}

void initPokedex(Pokedex *p) {
	*p = NULL;
}

GameUser newGameUser(String playerName) {
	GameUser user;
	
	user.playerDeck = newDeck();
	user.playerTile = newTile();
	user.playerDiscard = newDiscard(MAX_POKEMON);
	
	strcpy(user.playerName, playerName);
	
	return user;
}

void displayPokemonArrayList(PokemonList pokeList) {
	int i;
	printf("{\n");
	// to do code logic here
	for(i = 0; i < pokeList.count; i++){
		printf("%5s- {%d | %s - ", " ", pokeList.pokeList[i].pokeID, pokeList.pokeList[i].pokeName);
		displayType(pokeList.pokeList[i].pokeType.mainType);
		printf(" }\n\n");
	}
	
	printf("}\n");
}

StackPokemonList initPokemonStackPokemonList(int size){
	StackPokemonList *newPokemonList;
	
	newPokemonList = malloc(sizeof(StackPokemonList) * size);
	newPokemonList->count = -1;
	newPokemonList->max = size;
	
	return *newPokemonList;
}

bool isEmptyStackPokemonList(StackPokemonList pokeList){
	return pokeList.count == -1 ? true : false;
}

bool isFullStackPokemonList(StackPokemonList pokeList){
	return (pokeList.count == (MAX_POKEMON - 1)) ? true : false;
}

void pushStackPokemonList(StackPokemonList *pokeList, Pokemon pokemon){
	if(isFullStackPokemonList(*pokeList)){
		printf("Pokemon Stack List is FULL\n");
	}else{
		pokeList->pokeList[++pokeList->count] = pokemon;	
	}
}

Pokemon peekStackPokemonList(StackPokemonList pokeList){
	return pokeList.pokeList[pokeList.count];	
}

void popStackPokemonList(StackPokemonList *pokeList){
	if(isEmptyStackPokemonList(*pokeList)){
		printf("Pokemon Stack List is EMPTY\n");
	}else{
		--pokeList->count;
	}
}

void displayPokemonStackArrayList(StackPokemonList pokeList) {
	printf("{\n");
	// to do code logic here
	StackPokemonList container = initPokemonStackPokemonList(MAX_POKEMON);
	
	while(!isEmptyStackPokemonList(pokeList)){
		pushStackPokemonList(&container, peekStackPokemonList(pokeList));
		popStackPokemonList(&pokeList);
	}
	
	
	while(!isEmptyStackPokemonList(container)){
		Pokemon holder = peekStackPokemonList(container);
		printf("%5s- %d | %s - ", " ", holder.pokeID, holder.pokeName);
		displayType(holder.pokeType.mainType);
		printf(" }\n");
		popStackPokemonList(&container);
	}
	
	printf("}\n");
}

void displayPokemonLinkedList(Pokedex p) {
	printf("{\n");
	// to do code logic here
	Pokedex head = p;
	
	while(head != NULL){
		printf("%5s- {%d | %s - ", " ", head->dataInfo.pokeID, head->dataInfo.pokeName);
		displayType(head->dataInfo.pokeType.mainType);
		printf(" }\n\n");
		head = head->link;
	}
	
	printf("}\n");
}

bool isFullPokemonCircularArray(Tile t){
	return (t.end + (MAX_SPACE - 2)) % MAX_SPACE == t.start;
}

bool isEmptyPokemonCircularArray(Tile t){
	return (t.end + (MAX_SPACE - 1)) % MAX_SPACE == t.start;
}

Pokemon frontPokemonCircularArray(Tile t){
	if(!isEmptyPokemonCircularArray(t)){
		return t.list[t.start];
	}
}

void dequeuePokemonCircularArray(Tile *t){
	if(!isEmptyPokemonCircularArray(*t)){
		t->start = (t->start + (MAX_SPACE - 1)) % MAX_SPACE;
	}
	
}

void displayPokemonCircularArray(Tile t) {
	printf("{\n");
	// to do code logic here
	while(!isEmptyPokemonCircularArray(t)){
		Pokemon p = frontPokemonCircularArray(t);
		
		printf("%5s- {%d | %s - ", " ", p.pokeID, p.pokeName);
		displayType(p.pokeType.mainType);
		printf(" }\n\n");
		
		dequeuePokemonCircularArray(&t);
	}
	
	printf("}\n");
}

void pushPokemonDeck(VSpace *vs, StackList *list, Pokemon pokemon){
	int newNode = allocSpace(vs);
	
	if(newNode == -1){
		printf("NO MORE SPACE!!\n\n");
	}
	
	vs->data[newNode].dataDetail = pokemon;
	vs->data[newNode].pos = *list;
	*list = newNode;
}

void popPokemonDeck(VSpace *vs, StackList *list){
	if(*list != -1){
		StackList temp = *list;
		*list = vs->data[*list].pos;
		freeSpace(vs, temp);
	}

}

Pokemon peekPokemonDeck(VSpace vs, StackList list){
	return vs.data[list].dataDetail;
}

void displayPokemonDeck(VSpace vs, StackList list) {
	printf("{\n");
	// to do code logic here
	StackList container = newStackList(), holder;
	
	while(list != -1){
		pushPokemonDeck(&vs, &container, vs.data[list].dataDetail);
		holder = list;
		list = vs.data[list].pos;
		vs.data[holder].pos = -1;
		popPokemonDeck(&vs, &holder);
	}

	while(container != -1){
		Pokemon p = peekPokemonDeck(vs, container);	
		
		printf("%5s- {%d | %s - ", " ", p.pokeID, p.pokeName);
		displayType(p.pokeType.mainType);
		printf(" }\n\n");
		
		holder = container;
		container = vs.data[container].pos;
		vs.data[holder].pos = -1;
		popPokemonDeck(&vs, &holder);
	}
	
	printf("}\n");
}

void displayGameUser(GameUser user) {
	printf("Player Name: %s\n", user.playerName);
	printf("Pokemon on Deck\n");
	displayPokemonDeck(user.playerDeck.space, user.playerDeck.stack);
	printf("Pokemon on Tile\n");
	displayPokemonCircularArray(user.playerTile);
	printf("Pokemon on Graveyard\n");
	displayPokemonArrayList(user.playerDiscard);
}

Type newType(int type) {
	Type t;
	
	t.mainType = type;
	t.resistantTo = t.strongAgainst = t.vulnerableTo = t.weakAgainst = 0;
	
	return t;
}

void initStat(Stat s, int hp, int attack, int defense, int sa, int sd, int speed, int oad) {
	s[0] = hp;
	s[1] = attack;
	s[2] = defense;
	s[3] = sa;
	s[4] = sd;
	s[5] = speed;
	s[7] = oad;
} 

Pokemon newPokemon(int pokeID, String pokeName, Type pokeType, Stat pokeStats) {
	Pokemon p;
	
	p.pokeID = pokeID;
	strcpy(p.pokeName, pokeName);
	p.pokeType = pokeType;
	memcpy(p.pokeStats, pokeStats, sizeof(int) * 7);
	
	return p;
}

void addPokemon(Pokedex *dex, Pokemon p) {
	Pokedex temp = malloc(sizeof(NodePM));
	
	if(temp != NULL) {
		temp->dataInfo = p;
		temp->link = *dex;
		*dex = temp;
	}
}
