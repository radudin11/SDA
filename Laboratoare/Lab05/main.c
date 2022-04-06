#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "TCoada.h"
#include "TStiva.h"
#include "my_func.h"


/* numar maxim elemente coada / stiva */
#define MAX 256 

typedef struct
{ 
	int x, y;
} TPunct;

/* insereaza N elemente in coada c - elemente de tip TPunct
   cu valori intre v1 si v2 */
int GenereazaCoadaPuncte(void* c, size_t N, int v1, int v2)
{ 
  	int n = 0;
  	TPunct p;

  	srand(time(NULL));
  	for(; N > 0; N--)
  	{
    	p.x = rand() % (v2-v1+1) + v1; 
    	p.y = rand() % (v2-v1+1) + v1;
  
		if (!IntrQ(c, &p)) 
			return n;
		n++;
  	}
  	return n;
}

/* insereaza N elemente in stiva s - elemente de tip TPunct
   cu valori intre v1 si v2 */
int GenereazaStivaPuncte(void* s, size_t N, int v1, int v2)
{ 
	int n = 0;
  	TPunct p;

  	srand(time(NULL));
  	for(; N > 0; N--)
  	{
    	p.x = rand() % (v2-v1+1) + v1; 
    	p.y = rand() % (v2-v1+1) + v1;
  
		if (!Push(s, &p)) 
			return n;
		n++;
  	}
  	return n;
}

int AfiPct(void *a)
{ 
	printf("[%d %d] ", (*(TPunct*)a).x, (*(TPunct*)a).y); 
	return 1;
}




int main()
{ 
	void *c, *s;
  	int lgc, lgs;

  	c = InitQ(sizeof(TPunct),MAX);
	if (!c) 
		return 1;

  	s = InitS(sizeof(int),MAX);
	if (!s) 
	{
		DistrQ(&c); 
		return 1;
	}

  	lgc = GenereazaCoadaINT(c, 8, -5, 5);
  	lgs = GenereazaStivaINT(s, 6, -5, 5);
	


	printf("\nCoada cu %d elemente\n", lgc);
  	AfisareQ(c, AfiINT);
  	printf("\n\nStiva cu %d elemente\n", lgs);
   	AfisareS(s, AfiINT);

 	/* apeluri functii */
	printf("\n\n\nTASK1\n\n");

	printf("nr de elem: %d\n", TASK1(s, 0));
  	printf("\n\nStiva cu %d elemente\n", lgs);
   	AfisareS(s, AfiINT);


	printf("\n\n\nTASK2\n\n");
	int nr;
	printf("aici");
	void* saux = TASK2(c, 2, &nr);
	printf("\n\nStiva cu %d elemente\n", nr);
   	AfisareS(saux, AfiINT);

	printf("\n\n\nTASK3\n\n");
	void* s_even = InitS(sizeof(int), MAX);
	void* q_odd = InitQ(sizeof(int), MAX);
	TASK3(s, s_even, q_odd);
	printf("Coada de elemente impare:\n");
	AfisareQ(q_odd, AfiINT);
	printf("Stiva de elemente pare:\n");
	AfisareS(s_even, AfiINT);

	DistrS(&s);
  	DistrQ(&c);
  	return 0;
}