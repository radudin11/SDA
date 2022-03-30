#include "persoana.h"
#include "thash.h"
#include "tlg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int codHashPers(void * element)
{
	TPers * pers = (TPers *) element;
	return *(pers->nume) - 'A';
}

void afisarePers(void * element)
{
	TPers * pers = (TPers *) element;
	printf("%s - %d\n", pers->nume, pers->varsta);
}

TLG citesteListaPers() {
	char * line = NULL;
    int len = 0;
	TLG L = NULL;
    
	while (getline(&line, &len, stdin) != -1) {
		char * nume = strtok(line, " ");
		char * varsta = strtok(NULL, " ");

		if (varsta[strlen(varsta) - 1] == '\n')
			varsta[strlen(varsta) - 1] = '\0';

		TPers * pers = malloc(sizeof(TPers));
		if (pers == NULL)
			return L;
        

		strcpy(pers->nume, nume);
		pers->varsta = atoi(varsta);
        Ins_OrdLG(&L, (void *) pers, cmpPers);
    }
	return L;
}

int cmpPers(void * e1, void * e2)
{
	TPers * pers1 = (TPers *) e1;
	TPers * pers2 = (TPers *) e2;

    return strcmp(pers1->nume, pers2->nume);
}

TH * GenerareHashPers(TLG listaPers)
{
    TH *h = NULL;
	TLG p;
    TPers * pers;
	int rez;

	/* calcul dimensiuni maxime pt tabela hash */
	size_t M = ('Z'-'A');

	/* initializare tabela hash */
	h = (TH *) InitTH(M, codHashPers);
	if(h == NULL)
		return NULL;

	for(p = listaPers; p != NULL; p = p->urm) {
        pers = (TPers *) malloc(sizeof(TPers));
        if(pers == NULL)
						return h;

        memcpy(pers, p->info, sizeof(TPers));
		rez = InsTH(h, pers, cmpPers, cmpAge);
        if(rez) {
						free(pers);
						return h;
		}

	}

	return h;
}

int cmpAge(void* e1, void* e2) {
    int age1 = ((TPers*) e1)->varsta;
    int age2 = ((TPers*) e2)->varsta;

    return age1 - age2;
}