/*-- functiiLista.c --*/
#include <ctype.h>
#include "tlista.h"

/*--- operatii de baza pentru lista simplu inlantuita ---*/

TLista AlocCelula(int e)          /* adresa celulei create sau NULL */
{ TLista aux = (TLista)malloc(sizeof(TCelula));  /* (1) incearca alocare */
  if (aux)                            /* aux contine adresa noii celule */
  { aux->info = e;                   /* (2,3) completeaza noua celula */
    aux->urm = NULL;
  }
  return aux;             /* rezultatul este adresa noii celule sau NULL */
}

void AfisareL(TLista L)
       /* afiseaza valorile elementelor din lista */
{
  printf("Lista: [");                      /* marcheaza inceput lista */
  for (; L != NULL; L = L->urm)       /* pentru fiecare celula */
    printf("%d ", L->info);              /* afiseaza informatie */
  printf("]");                               /* marcheaza sfarsit lista */
}

void DistrugeL(TLista* aL)
{
  TLista aux;
  while(*aL)
  {
    aux = *aL;
    *aL = aux->urm;
    free(aux);
  }
}

TLista CitireL(int *lg)     /* construieste lista cu elemente citite */
{ TLista L = NULL, u, aux;
  int x;
  char ch;
  for(*lg = 0; scanf("%i", &x) == 1; )
  {
    aux = AlocCelula(x);           /* incearca inserarea valorii citite */
    if(!aux) return L;              /* alocare esuata => sfarsit citire */
    if(L == NULL){
      L = aux;
    } else {
      //lista ordonata crescator
      
      if(aux->info < L->info) {
        aux->urm = L;
        L = aux;
      } else {
        u = L;
        while (u->urm != NULL && u->urm->info <= aux->info)
        u = u->urm;

        aux->urm = u->urm;
        u->urm = aux;
      }
    }
    
    (*lg)++;
  }

  while((ch=getchar()) != EOF && ch != '\n');
  return L;                     /* intoarce lista rezultat */
}
void f1(TLista x, int div) {
  int i = 1;
  
  for ( ;x != NULL && x->urm != NULL; x = x->urm->urm) {
    if (x->info % div == 0 && x->urm->info % div == 0) {
      printf("Indicii: %d, %d; Numerele %d, %d\n", i, i+1, x->info, x->urm->info);
    }
    i += 2;
  }
}

int compare(TLista A, TLista B) {
  for (TLista I = A; I != NULL; I = I->urm) {
    int sem = 0;
    for(TLista II = B; II != NULL; II = II->urm) {
      if(I->info == II->info)
        sem = 1;
    }
    if (!sem) return 0;
  }

  for (TLista I = B; I != NULL; I = I->urm) {
    int sem = 0;
    for(TLista II = A; II != NULL; II = II->urm) {
      if(I->info == II->info)
        sem = 1;
    }
    if (!sem) return 0;
  }

  return 1;
}

int f3(TLista x, int *inc, int *sf) {
  *inc = 0;
  *sf = 0;

  int ninc = 1, nsf = 0;
  for (; x != NULL; x = x->urm) {
    nsf++;
    TLista nxt = x->urm;
    if(nxt == NULL || x->info > nxt->info) {
      if(nsf - ninc) {
        *sf = nsf;
        *inc = ninc;
      }
      ninc = nsf + 1;
    }
  }
  if (*sf - *inc == 0) {
    *sf = -1;
    *inc = -1;
    return 0;
  }
  return *sf - *inc + 1;
}
