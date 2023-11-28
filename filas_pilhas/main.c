#include <stdio.h>
#include <stdlib.h>
#include "TF.h"
#include "TP.h"

TP *f2p(TF *f){
    TF *fila = f;
    TP *pilha1 = TP_inicializa(), *pilha2 = TP_inicializa();

    while(!(TF_vazia(fila))){
        int num = TF_retira(fila);
        TP_push(pilha1, num);
    }
    while(!(TP_vazia(pilha1))){
        int num = TP_pop(pilha1);
        TP_push(pilha2, num);
    }
    return pilha2;
}

TF *inv_fila(TF *f){
    TF *fila = f, *fila_inv = TF_inicializa();
    TP *pilha = TP_inicializa();
    int num;
    while (!TF_vazia(fila)){
        num = TF_retira(fila);
        TP_push(pilha, num);
    }
    while (!TP_vazia(pilha)){
        num = TP_pop(pilha);
        TF_insere(fila_inv, num);
    }
    TP_libera(pilha);
    return fila_inv;
}

TF *junta_filas(TF *f1, TF *f2){
    TF *fila1 = f1, *fila2 = f2, *fila_junta = TF_inicializa(), *aux = TF_inicializa();
    int num;

    while(!TF_vazia(fila1)){
        num = TF_retira(fila1);
        TF_insere(fila_junta, num);
        TF_insere(aux, num);
    }
    while(!TF_vazia(aux)){
        num = TF_retira(aux);
        TF_insere(fila1, num);
    }
    while(!TF_vazia(fila2)){
        num = TF_retira(fila2);
        TF_insere(fila_junta, num);
        TF_insere(aux, num);
    }
    while(!TF_vazia(aux)){
        num = TF_retira(aux);
        TF_insere(fila2, num);
    }
    TF_libera(aux);
    return fila_junta;
}

TP *retira_pares(TP *p){
    TP *pilha = p,*aux = TP_inicializa();
    int num;
    while(!TP_vazia(pilha)){
        num = TP_pop(pilha);
        if (num%2) TP_push(aux, num);
    }
    while(!TP_vazia(aux)){
        TP_push(pilha, TP_pop(aux));
    }
}

TF *p2f(TP *p){
    TP *pilha = p;
    TF *fila = TF_inicializa();
    int num;
    while(!TP_vazia(pilha)){
        num = TP_pop(pilha);
        TF_insere(fila, num);
    }
    return fila;
}

int main(void){
    TP *pilha = TP_inicializa();
    TF *fila = TF_inicializa();
    int num;
    for (int i=0; i<5; i++){
        scanf("%d", &num);
        TP_push(pilha, num);
    }

    TP_imprime(pilha);
    fila = p2f(pilha);
    TF_imprime(fila);
    printf("\n%d", TF_retira(fila));

    TF_libera(fila);
    TP_libera(pilha);
    return 0;
}
