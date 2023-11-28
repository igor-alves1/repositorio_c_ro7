#include <stdio.h>
#include <stdlib.h>
#include "TLSE.h"
#include "TP.h"
#include "TF.h"

void mult_k1(TP *p, int k){
    TP *pilha = p, *aux = TP_inicializa();
    int num;
    while(!TP_vazia(pilha)){
        num = TP_pop(pilha);
        if (num%k){
            TP_push(aux, num);
        }
    }
    while (!TP_vazia(aux)){
        TP_push(pilha, TP_pop(aux));
    }
    TP_libera(aux);
}

TP *mult_k2(TP *p, int k){
    TP *aux = TP_inicializa(), *nova = TP_inicializa(), *pilha = p;
    int num;

    while(!TP_vazia(pilha)){
        TP_push(aux, TP_pop(pilha));
    }
    while(!TP_vazia(aux)){
        num = TP_pop(aux);
        TP_push(pilha, num);
        if (num%k) TP_push(nova, num);
    }
    TP_libera(aux);
    return nova;
}

int main(){
    TP *pilha = TP_inicializa(), *pilha2 = TP_inicializa();
    int num, divisor;
    scanf("%d", &divisor);
    for (int i=0; i<5; i++){
        scanf("%d", &num);
        TP_push(pilha, num);
    }
    pilha2 = mult_k2(pilha, divisor);
    TP_imprime(pilha);
    printf("\n");
    TP_imprime(pilha2);

    TP_libera(pilha2);
    TP_libera(pilha);
    return 0;
}
