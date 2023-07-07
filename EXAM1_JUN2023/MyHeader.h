#ifndef MYHEADER_H
#define MYHEADER_H
#include <stdbool.h>

#define MAX_TYPE 100
#define MAX_POKEMON 100
#define MAX_SPACE 100

typedef char String[20];
typedef int Stat[7];

typedef struct {
	int mainType;
    int strongAgainst;
    int weakAgainst;
    int resistantTo;
    int vulnerableTo;
} Type;

typedef struct {
    int pokeID;
    String pokeName;
    Type pokeType;
    Stat pokeStats;
} Pokemon;

typedef struct {
    Pokemon *pokeList;
    int count;		//will act as top when used as a stack
    int max;
} PokemonList, StackPokemonList;

typedef struct {
     Pokemon dataDetail;
     int pos; // Next
} PokemonNode;

typedef struct {
     PokemonNode data[MAX_SPACE];
     int avail;
} VSpace;

typedef int StackList;

typedef struct { 
     StackList stack;
     VSpace space;
} Deck;

typedef struct {
     Pokemon list[MAX_POKEMON];
     int start;
     int end;
} Tile;

typedef struct nodePokemon{
     Pokemon dataInfo;
     struct nodePokemon *link;
} NodePM, *Pokedex;

typedef struct {
     String playerName;
     Deck playerDeck;
     Tile playerTile;
     StackPokemonList playerDiscard;
} GameUser;

int allocSpace(VSpace *vs);
void freeSpace(VSpace *vs, int loc);
void displayPokemon(Pokemon p);
void displayPokemonDetail(Pokemon p);
void displayPokemonStats(Pokemon p);
void displayType(int type);

VSpace newVSpace();
Tile newTile();
Deck newDeck();
StackPokemonList newDiscard(int size);
StackList newStackList();
void initPokedex(Pokedex *p);
GameUser newGameUser(String playerName);

void displayPokemonArrayList(PokemonList pokeList);
void displayPokemonStackArrayList(StackPokemonList pokeList);
void displayPokemonLinkedList(Pokedex p);
void displayPokemonCircularArray(Tile t);
void displayPokemonDeck(VSpace vs, StackList list);
void displayGameUser(GameUser user);

Type newType(int type);
void initStat(Stat s, int hp, int attack, int defense, int sa, int sd, int speed, int oad);
Pokemon newPokemon(int pokeID, String pokeName, Type pokeType, Stat pokeStats);
void addPokemon(Pokedex *dex, Pokemon p);

StackPokemonList initPokemonStackPokemonList();
bool isEmptyStackPokemonList(StackPokemonList pokeList);
bool isFullStackPokemonList(StackPokemonList pokeList);
void pushStackPokemonList(StackPokemonList *pokeList, Pokemon pokemon);
Pokemon peekStackPokemonList(StackPokemonList pokeList);
void popStackPokemonList(StackPokemonList *pokeList);

bool isFullPokemonCircularArray(Tile t);
bool isEmptyPokemonCircularArray(Tile t);
Pokemon frontPokemonCircularArray(Tile t);
void dequeuePokemonCircularArray(Tile *t);

void pushPokemonDeck(VSpace *vs, StackList *list, Pokemon pokemon);
void popPokemonDeck(VSpace *vs, StackList *list);
Pokemon peekPokemonDeck(VSpace vs, StackList list);

//// Must have dead pokemon pile to be returned 
//void ressurect();
//
//// Call highest rated card
//void summon();


#endif
