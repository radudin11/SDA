#include "thash.h"

#ifndef CARTI
#define CARTI

typedef struct {
	char titlu[50];
	char autor[30];
	char editura[30];
} TCarte;


int codHash(void * element);
void afisareCarte(void * element);
TLG citesteListaCarti(char * numeFisier);
int cmpCarte(void * e1, void * e2);
TH * GenerareHash(TLG listaCarti);

#endif