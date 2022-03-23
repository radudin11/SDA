/*--- testListaG.c ---*/
#include <ctype.h>
#include <stdio.h>
#include "tlg.h"

#define MAX 5  /* număr maxim de elemente din lista */



int f1(TLG L, int (*fcmp)(void*)) {
  int app = 0;
  for(;L != NULL; L=L->urm)
    if(fcmp(L->info)) app++;
  return app;
}

int main ()
{ 
  TLG L = NULL;     
  
  L = CitireL_Carte();  /* construiește lista generica cu elemente întregi */
  AfisareLG(L, afi_carte);

  /* apeluri functii implementate */
  Elim(&L, verificaAn_Carte, free_Carte);
  AfisareLG(L, afi_carte);
  

  DistrugeLG(&L, free_Carte);
}