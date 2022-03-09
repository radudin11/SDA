/*--- testLista.c ---*/
#include <ctype.h>
#include <stdio.h>
#include "tlista.h"

TLista CitireL(int *lg)     /* construieste lista cu elemente citite */
{ TLista L = NULL, u, aux;
  int x;
  char ch;
  for(*lg = 0; scanf("%i", &x) == 1; )
  {
    aux = AlocCelula(x);           /* incearca inserarea valorii citite */
    if(!aux) return L;              /* alocare esuata => sfarsit citire */
    if(L == NULL) L = aux;
    else u->urm = aux;
    u = aux;
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

int main ()
{ TLista x = NULL;     /* Lista prelucrata */
  int lx;           /* lungime lista */

  for (;;)
  {
    /* citeste si afiseaza lista */
    printf("\nIntroduceti valori elemente terminate cu valoare nenumerica:\n");
    x = CitireL(&lx);
    AfisareL(x);
    if(!x) continue;

    /* apeluri functii implementate */
    printf("Introduceti numarul functiei de testat:\n");
    char choice = getchar();

    /* (test f1) afiseaza elementele consecutive din lista x si indicii acestore daca sunt multiplii de div */
    if(choice == '1') {
      int div = 2;
      f1(x, div);
    }
    
    /* (test compare) compara 2 liste astfel incat sa contina acceleasi elemente*/
    
    // Citire lista 2
    if(choice == '2') {
      printf("\nIntroduceti valori elemente terminate cu valoare nenumerica pt lista 2:\n");
      int ll = 0;
      TLista l = NULL;
      l = CitireL(&ll);
      AfisareL(l);
      if(!l) continue;
    
      if(compare(x, l))
        printf("Au aceleasi elemente");
      else
        printf("Nu au aceleasi elemente");
      
      DistrugeL(&l);
    }
    
   
    // sfarsit test pt compare

    /* test f3*/
    if(choice == '3') {
      int inc, sf;
      printf("lungime = %d\n",f3(x, &inc, &sf));
      printf("Indicii sunt %d %d\n", inc, sf);
    }

    DistrugeL(&x);
    printf ("\n  Inca un test ? [d/n]");
    if (getchar() == 'n') break;
  }
}
