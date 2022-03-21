#include <stdio.h>
#include <stdlib.h>

int fh_siruri(void *x) {
    char *str = (char*)x;
    return (str[0] - 'a');
}

int fcmp_siruri(void* x, void* y) {
    if(strcmp((char*)x, (char*)y)) return 0;
    return 1;
}
void afis_str(void *x) {
    printf("%s", (char*)x);
}

int main() {
    TH *a;
    a = initHash(30, fh_siruri);
    if(!a) return -1;
    char* el;
    InsTH(a, (void*)el, fcmp_siruri);
}