/*-- tlg.h --- LISTA SIMPLU INLANTUITA GENERICA ---*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#ifndef _LISTA_GENERICA_
#define _LISTA_GENERICA_

typedef struct celulag
{
  void* info;           /* adresa informatie */
  struct celulag *urm;   /* adresa urmatoarei celule */
} TCelulaG, *TLG; 	/* tipurile Celula, Lista generice */

typedef struct carte
{
  char* titlu;
  int anAparitie;
  char isbn[30];
}TCarte;

/* functii lista generica */
TLG Aloc_CelulaG(void* x);

int Ins_IncLG(TLG*, void*);  /*- inserare la inceput reusita sau nu (1/0) -*/

void DistrugeLG(TLG* aL, void (*fe)(void*)); /* distruge lista */

void Elim(TLG *L, int (*cmp)(void*), void (*free_elem)(void*));

/* afiseaza elementele din lista, folosind o functie de Afișare element specific*/
void AfisareLG(TLG, void (*afi_el)(void*));

TLG CitireL_Int();
void afi_int(void* el); 

TCarte* Aloca_Carte();
TLG CitireL_Carte();
void free_Carte(void *carte);
void afi_carte(void* el);
int verificaAn_Carte(void* carte);



#endif