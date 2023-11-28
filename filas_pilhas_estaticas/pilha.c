#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct pilha{
    int vet[10];
    int topo;
} TP;

TP *TP_inicializa(void){
    TP *pilha = (TP *)malloc(sizeof(TP));
    pilha->topo = -1;
    return pilha;
}

void TP_push(TP *pilha, int elem){
    if (pilha->topo < 9){
        pilha->topo += 1;
        pilha->vet[pilha->topo] = elem;
    } else printf("n pode fazer isso nao fudido");
}

int TP_pop(TP *pilha){
    if (pilha->topo < 0) printf("n pode fazer isso nao fudido");
    else{
        pilha->topo -= 1;
        return pilha->vet[(pilha->topo)+1];
    }
}

void TP_libera(TP *pilha){
    free(pilha);
}

int TP_vazia(TP *pilha){
    if(pilha->topo > -1) return 0;
    return 1;
}
