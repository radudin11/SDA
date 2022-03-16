/*--- testLista.c ---*/
#include <ctype.h>
#include <stdio.h>
#include "tlista.h"


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
    //if (getchar() == 'n') break;
    char exit = getchar();
    if (exit == 'n') break;
  }
}
