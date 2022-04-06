/*-- testHash.c  */
#include <stdio.h>
#include "tlg.h"
#include "thash.h"
#include "persoana.h"
#include <string.h>

int main()
{
	/* Citeste o lista de carti din fisier */
	TLG listaPers = citesteListaPers();
	if (listaPers == NULL) {
		printf("Lista nu a putut fi generata\n");
        return 0;
	}

	printf("=========== LISTA CARTI ===========\n");
	Afisare(&listaPers,afisarePers);

	TH * h = NULL;
	h = GenerareHashPers(listaPers);
	if (h == NULL) {
		printf("Tabela hash nu a putut fi generata\n");
        return 0;
	}

	printf("\n\n=========== TABELA HASH ===========\n");
	AfiTH(h, afisarePers);
	//afisarePers(h->v[12]->info);

  	DistrugeLG(&listaPers, free);
	DistrTH(&h, free);
  	return 0;
}
