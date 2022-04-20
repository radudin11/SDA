#include "my_func.h"

int Numara(TArb r) {
    if (!r) {
        return 0;
    }

    int rez = 0;
    rez += Numara(r->dr);
    if (r->dr && r->st) {
        if (r->dr->info + r->dr->info > r->info)
            rez += 1;
    }
    rez += Numara(r->st);
    return rez;
}

int Parcurge(TArb r) {
    if (!r) {
        return 0;
    }

    int rez = 0;
    rez += Parcurge(r->dr);
    
    int ordin = 0;
    if (r->dr)
        ordin++;
    
    if (r->st)
        ordin++;
    
    if (ordin) 
        printf("Nodul %d, orind %d\n", r->info, ordin);
    else
        rez += 1;

    rez += Parcurge(r->st);

    return rez;
}

int VerificaAux(TArb r, int nivel, int nivelcrt) {
    if (!r)
        return 1;
    
    int rez = 1;
    if (nivel == nivelcrt) {
        if (r->dr && r->st)
            rez =  1;
        else
            rez = 0;
        return rez;
    }
    rez *= VerificaAux(r->dr, nivel, nivelcrt + 1);
    rez *= VerificaAux(r->st, nivel, nivelcrt + 1);
}

int Verifica(TArb r, int nivel) {
    return VerificaAux(r, nivel, 0);
}