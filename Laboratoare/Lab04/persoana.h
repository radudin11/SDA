#include "thash.h"

#ifndef PERSOANA
#define PERSOANA

#define MAX_LEN_NUME 20

typedef struct persoana
{
    char nume[MAX_LEN_NUME];
    int varsta;
}TPers;


int codHashPers(void * element);
void afisarePers(void * element);
TLG citesteListaPers();
int cmpPers(void * e1, void * e2);
TH * GenerareHashPers(TLG listaPers);
int cmpAge(void* e1, void* e2);


#endif