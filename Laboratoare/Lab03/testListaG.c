/*--- testListaG.c ---*/
#include <ctype.h>
#include <stdio.h>
#include "tlg.h"

#define MAX 5  /* număr maxim de elemente din lista */

TLG CitireL_Int()     /* construieste lista cu elemente întregi - MAX elemente */
{ TLG L = NULL, u, aux;
  int *elem, nr = 0;

  printf("\nConstructie lista generică cu %i elemente întregi\n", MAX);
  for(nr = 0; nr < MAX; nr++)
  {
    int* elem = (int*)malloc(sizeof(int));
    if(!elem) return L;

    scanf("%i", elem);

    aux = Aloc_CelulaG(elem);           /* incearca inserarea valorii citite */
    if(!aux) {	/* alocare esuata => sfarsit citire */
	free(elem); 
	return L;
    }       
       
    if(L == NULL) L = aux;
    else u->urm = aux;
    u = aux;
  }
  
  return L;                     /* intoarce lista rezultat */
}

void afi_int(void* el)
{
	printf("%i ", *(int*)el);
}

int main ()
{ 
  TLG L = NULL;     
  
  L = CitireL_Int();  /* construiește lista generica cu elemente întregi */
  AfisareLG(L, afi_int);

  /* apeluri functii implementate */

  DistrugeLG(&L, free);
}