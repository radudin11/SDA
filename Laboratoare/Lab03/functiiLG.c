/*--- functiiLG.c -- operatii de baza pentru lista simplu inlantuita generica---*/
#include "tlg.h"
#define MAX_TITLU 50
#define MAX 6
#define AN 1200
TLG Aloc_CelulaG(void* x)
{
	TLG aux;
  	aux = (TLG)malloc(sizeof(TCelulaG));
   	if(!aux) return NULL;
   	
	aux->info = x;
	aux->urm = NULL;
	return aux;
}

int Ins_IncLG(TLG* aL, void* ae)
{
	TLG aux = Aloc_CelulaG(ae);
	if(!aux)
	    return 0;

	aux->urm = *aL;
	*aL = aux;

	return 1;
}

void DistrugeLG(TLG* aL, void (*free_elem)(void*)) /* distruge lista */
{
	TLG aux;
	while(*aL != NULL)
    	{
        		aux = *aL;     /* adresa celulei eliminate */
        		if (!aux)
            		return;

        		free_elem(aux->info);  /* elib.spatiul ocupat de element*/
        		*aL = aux->urm;    /* deconecteaza celula din lista */
        		free(aux);   /* elibereaza spatiul ocupat de celula */
    	}
}


void AfisareLG(TLG L, void (*afiEL)(void*))
{
        if(!L) {
           printf("Lista vida\n");
           return;
        }

	printf("Lista: [\n");
	for(; L; L = L->urm) 
		afiEL(L->info);
    
	printf("]\n");
}

TCarte* Aloca_Carte() {
	TCarte* carte = (TCarte*)malloc(sizeof(TCarte));
	if(!carte) return NULL;
	carte->titlu = (char*)malloc(MAX_TITLU);
	if(!carte->titlu) {
		free(carte);
		return NULL;
	}
	return carte;
}

void free_Carte(void *carte) {
	free(((TCarte*)carte)->titlu);
	free((TCarte*)carte);
}

void afi_int(void* el)
{
	printf("%i ", *(int*)el);
}

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

TLG CitireL_Carte()     /* construieste lista cu elemente carti - MAX elemente */
{ TLG L = NULL, u, aux;

  printf("\nConstructie lista generică cu %i elemente carti\n", MAX);
  for(int nr = 0; nr < MAX; nr++)
  {
    TCarte* elem = Aloca_Carte();
    if(!elem) return L;

    scanf("%s", elem->titlu);
	scanf("%d", &(elem->anAparitie));
	scanf("%s", elem->isbn);

    aux = Aloc_CelulaG(elem);           /* incearca inserarea valorii citite */
    if(!aux) {	/* alocare esuata => sfarsit citire */
	free_Carte(&elem); 
	return L;
    }       
       
    if(L == NULL) L = aux;
    else u->urm = aux;
    u = aux;
  }
  
  return L;                     /* intoarce lista rezultat */
}

void afi_carte(void* el)
{
	printf("Titlu: %s\n", ((TCarte*)el)->titlu);
	printf("An aparitie: %d\n", ((TCarte*)el)->anAparitie);
	printf("Isbn: %s\n\n\n", ((TCarte*)el)->isbn);

}

int verificaAn_Carte(void* carte) {
	
	if (((TCarte*)carte)->anAparitie == AN) return 1;
	return 0;

}

void Elim(TLG *L, int (*cmp)(void*), void (*free_elem)(void*)){
	while ((*L) != NULL  && cmp((*L)->info)) {
		printf("\nL in while= %p\n",(*L));
		TLG aux = *L;
		*L = (*L)->urm;
		free_elem(aux->info);
		free(aux);
	}
	printf("\nL afar = %p\n",(*L));
	if(!(*L)) {
		printf("\nL in if= %p\n",(*L));
		return;
	}
	TLG q = (*L);
	for (TLG p = (*L)->urm; p != NULL;) {
		if(cmp(p->info)) {
			q->urm = p->urm;
			free_elem(p->info);
			free(p);
			p = q->urm;
		} else {
			q = p;
			p = p->urm;
		}
	}
}