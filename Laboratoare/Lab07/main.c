/**-- test-ab.c --  prelucreaza arbori binari cu chei intregi --*/
#include "tarb.h"
#include "my_func.h"
/*-- se completeaza cu definitiile functiilor implementate --*/

void RSD(TArb a)
{
	if(!a) {printf("-"); return;}
	if(!a->st && !a->dr) {printf(" %d ", a->info); return;}
	printf(" %d ", a->info);
	printf("(");
	RSD(a->st);
	printf(",");
	RSD(a->dr);
	printf(")");
}

int main ()
{
	TArb arb;

	randomize();
	do {
		arb = ConstrAA (5, random(16), -50, 50);
		AfiArb (arb);
		printf ("noduri: %i   niveluri: %i\n", 
			NrNoduri(arb), NrNiv(arb));
		RSD(arb);

		/*-- se completeaza cu apelurile functiilor implementate --*/
		printf("\n\nNr de noduri cu func 1: %d\n", Numara(arb));

		int rezF2 = Parcurge(arb);
		printf("\nNumarul de noduri neafisate: %d\n", rezF2);

		int rezF3 = Verifica(arb, 1);
		if(rezF3)
			printf("F3 adevarat\n");
		else
			printf("F3 fals\n");

		DistrArb (&arb);
		printf ("\nInca un arbore ? [D/N] ");

		if (getchar() == 'n') break;
		printf("\n");
	} while (1);

	return 0;
}
