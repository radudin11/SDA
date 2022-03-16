/*-- tlista.h --- LISTA SIMPLU INLANTUITA cu elemente de tip intreg ---*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


#ifndef _LISTA_SIMPLU_INLANTUITA_
#define _LISTA_SIMPLU_INLANTUITA_

typedef struct celula
{ int info;
  struct celula * urm;
} TCelula, *TLista; /* tipurile Celula, Lista */

#define VidaL(L) ((L) == NULL)

/*-- operatii elementare --*/

TLista AlocCelula(int);          /* adresa celulei create sau NULL */
void   DistrugeL (TLista*);       /* elimina toate celulele din lista */

void AfisareL (TLista L);
TLista CitireL(int *lg);
void f1(TLista x, int div);
int compare(TLista A, TLista B);
int f3(TLista x, int *inc, int *sf); 

//void f1 (TLista x, int div);
#endif