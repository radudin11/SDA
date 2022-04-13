#include "my_struct.h"

#define NR_MAX_ELEM 100
#define SIZE_OF_WORD 30

int afiProc(void* ae) {
    TProc* proc = (TProc*)ae;
    printf("%d ", proc->PID);
    return 0;
}


int main() {
    // TProc proc;
    // void* q1 = InitQ(sizeof(TProc), NR_MAX_ELEM);
    // void* q2 = InitQ(sizeof(TProc), NR_MAX_ELEM);
    // void* q3 = InitQ(sizeof(TProc), NR_MAX_ELEM);
    // while (scanf("%d", &proc.PID) != EOF) {
    //     scanf("%d", &proc.priority);
    //     printf("%d %d\n", proc.PID, proc.priority);
    //     switch (proc.priority)
    //     {
    //     case 1:
    //         IntrQ(q1, (void*)(&proc));
    //         break;
    //     case 2:
    //         IntrQ(q2, (void*)(&proc)); 
    //         break;
    //     case 3:
    //         IntrQ(q3, (void*)(&proc)); 
    //         break;
        
    //     default:
    //         break;
    //     }
    // }

    // AfisareQ(q1, afiProc);
    // AfisareQ(q2, afiProc);
    // AfisareQ(q3, afiProc);



    // void* s = InitS(sizeof(char), NR_MAX_ELEM);
    // char word[NR_MAX_ELEM];
    // scanf("%s", word);
    // char *c = word;
    // while(*c != '\0') {
    //     Push(s, (void*)c);
    //     c++;
    // }
    // int i;
    // for(i = 0; !VidaS(s); i++) {
    //     Pop(s, word + i);
    // }
    // word[i+1] ='\0'; 
    // printf("%s\n", word);
    // DistrS(&s);

    char prop[NR_MAX_ELEM * 30];
    void *s2 = InitS(sizeof(char*), NR_MAX_ELEM);
    
    char org[NR_MAX_ELEM][SIZE_OF_WORD];
    char inv[NR_MAX_ELEM][SIZE_OF_WORD];
    fgets(prop, NR_MAX_ELEM * 30, stdin);
    prop[strlen(prop) - 1] = '\0';
    
    int i;
    char *tok = strtok(prop, " ");
    for (i = 0; tok != NULL; i++) {
        strcpy(org[i], tok);
        Push(s2, org[i]);
        tok = strtok(NULL, " ");
    }

    for(i = 0; !VidaS(s2); i++) {
        Pop(s2, inv[i]);
        printf("%s\n", inv[i]);
    }

    DistrS(&s2);







    return 0;
}