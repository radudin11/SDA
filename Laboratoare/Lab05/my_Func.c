#include "my_func.h"
#define MAX 256

int TASK1(void* S, int k) {
    void* saux = InitS(sizeof(int), MAX);
    if(!saux) return -1;
    void* el = malloc(sizeof(int));
    if(!el) {
        DistrS(&saux);
        free(el);
        return -1;
    }

    int cont = 0;

    while(!VidaS(S)) {
        Pop(S, el);
        Push(saux, el);
        if (*((int*)el) > k) {
            printf("%d ", *((int*)el));
            cont++;
        }
    }
    printf("\n");
    Rastoarna(S, saux);
    DistrS(&saux);
    free(el);
    return cont;
}

void* TASK2(void* q, int k, int* nr) {
    *nr = 0;
    void* qaux = InitQ(sizeof(int), MAX);
    void* el = malloc(sizeof(int));
    void* ret_s = InitS(sizeof(int), MAX);
    while(!VidaQ(q)) {
        ExtrQ(q, el);
        IntrQ(qaux, el);
        if (*(int*)el % k == 0) {
            (*nr)++;
            Push(ret_s, el);
            printf("%d", *(int*)el);
        }
    }
    printf("\n");
    ConcatQ(q, qaux);
    DistrQ(&qaux);
    free(el);
    return ret_s;
}

int TASK3(void* sinit, void* s, void* q) {
    void* saux = InitS(sizeof(int), MAX);
    if(!saux) return 0;
    void* el = malloc(sizeof(int));
    if(!el) {
        DistrS(&saux);
        free(el);
        return 0;
    }

    while(!VidaS(sinit)) {
        Pop(sinit, el);
        Push(saux, el);
        if (*((int*)el) % 2 == 0) {
            Push(s, el);
        } else {
            IntrQ(q, el);
        }
    }
    printf("\n");
    Rastoarna(sinit, saux);
    DistrS(&saux);
    free(el);
    return 1;

}

int GenereazaStivaINT(void* s, size_t N, int v1, int v2)
{ 
	int n = 0;
  	int p;

  	srand(time(NULL));
  	for(; N > 0; N--)
  	{
    	p = rand() % (v2-v1+1) + v1;
  
		if (!Push(s, &p)) 
			return n;
		n++;
  	}
  	return n;
}

int GenereazaCoadaINT(void* c, size_t N, int v1, int v2)
{ 
  	int n = 0;
  	int p;

  	srand(time(NULL));
  	for(; N > 0; N--)
  	{
    	p = rand() % (v2-v1+1) + v1;   
		if (!IntrQ(c, &p)) 
			return n;
		n++;
  	}
  	return n;
}


int AfiINT(void *a)
{ 
	printf("[%d] ", *(int*)a); 
	return 1;
}