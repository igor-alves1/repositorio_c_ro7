#include <stdio.h>
#include <stdlib.h>
#include "TLSE.h"

int igual(TLSE *l1, TLSE *l2){
    TLSE *u1 = l1, *u2 = l2;

    if (TLSE_vazia(u1) || TLSE_vazia(u2)) return 0;
    while (u1 && u2){
        if (u1->info != u2->info) return 0;
        u1 = u1->prox;
        u2 = u2->prox;
    }
    if (!u1 && !u2) return 1;
    return 0;
}

TLSE *junta_listas(TLSE *l1, TLSE *l2){
    TLSE *u1 = l1, *u2 = l2;

    if (TLSE_vazia(u2)) return u1;
    if (TLSE_vazia(u1)) return u2;
    while (u1->prox) u1 = u1->prox;
    u1->prox = u2;
    return l1;
}

int contrario(TLSE *l1, TLSE *l2){
    TLSE *u1 = l1, *u2 = l2, *u3 = TLSE_inicializa();
    int resultado;

    while (u1){
        u3 = TLSE_insere(u3, u1->info);
        u1 = u1->prox;
    }
    resultado = igual(u3, u2);
    TLSE_libera(u3);
    resultado = igual(u3, u2);
}

int misc_aux(TLSE *l, int k){
    if ((l->info%2)==(k%2)){
        if (!l->prox) return 1;
        return misc_aux(l->prox, k+1);
    }
    return 0;
}

int misc(TLSE *l){
    int k = 1;
    return misc_aux(l, k);
}

int main(){
    TLSE *lista1 = TLSE_inicializa(), *lista2 = TLSE_inicializa();
    for (int i=0; i<5; i++){
        int num;
        scanf("%d", &num);
        lista1 = TLSE_insere(lista1, num);
    }
    for (int i=0; i<5; i++){
        int num;
        scanf("%d", &num);
        lista2 = TLSE_insere(lista2, num);
    }
    printf("%d %d", misc(lista1), misc(lista2));
    TLSE_libera(lista1);
    TLSE_libera(lista2);

    return 0;
}
