/*-- testHash.c  */
#include <stdio.h>
#include "tlg.h"
#include "thash.h"
#include <string.h>

int main()
{
	/* Citeste o lista de carti din fisier */
	TLG listaCarti = citesteListaCarti("carti.txt");
	if (listaCarti == NULL) {
		printf("Lista nu a putut fi generata\n");
        return 0;
	}

	printf("=========== LISTA CARTI ===========\n");
	Afisare(&listaCarti, afisareCarte);

	TH * h = NULL;
	h = GenerareHash(listaCarti);
	if (h == NULL) {
		printf("Tabela hash nu a putut fi generata\n");
        return 0;
	}

	printf("\n\n=========== TABELA HASH ===========\n");
	AfiTH(h, afisareCarte);

  	DistrugeLG(&listaCarti, free);
	DistrTH(&h, free);
  	return 0;
}
