#include <stdio.h>
#include <stdlib.h>
#include "TLSE.h"

void inverte(TLSE **l){
    TLSE *u = (*l);
    (*l) = TLSE_insere(l, u->info);
    (*l)->prox = NULL;
    u = TLSE_retira(u, u->info);
    while(u){
        (*l) = TLSE_insere((*l), u->info);
        u = TLSE_retira(u, u->info);
    }
}

int main(){
    TLSE *lista = TLSE_inicializa();
    int n=0;
    while (n<5){
        int ingor;
        scanf("%d", &ingor);
        lista = TLSE_insere(lista, ingor);
        n++;
    }
    TLSE_imprime(lista);
    printf("\n");
    inverte(&lista);
    TLSE_imprime(lista);

    return 0;
}
