/**-- test-ab.c --  prelucreaza arbori binari cu chei intregi --*/
#include "tarb.h"

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

		DistrArb (&arb);
		printf ("\nInca un arbore ? [D/N] ");

		if (getchar() == 'n') break;
		printf("\n");
	} while (1);

	return 0;
}
