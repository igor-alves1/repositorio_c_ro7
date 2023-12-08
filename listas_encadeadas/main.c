#include <stdio.h>
#include <stdlib.h>
#include "TLSE.h"

TLSE *meio(TLSE *l, int *pos){
    if(!l){
        (*pos) = 0;
        return l;
    }
    int *posicao = pos;
    (*posicao) = 0;
    TLSE *p, *g;
    g = p = l;
    while(p){
        if(!((*posicao)%2)&&((*posicao)!=0)) g = g->prox;
        p = p->prox;
        (*posicao) += 1;
    }
    (*posicao)=(*posicao)/2 + 1;
}

int main(){
    TLSE *l = NULL;
    int n;
    do{
        scanf("%d", &n);
        if(n<0) break;
        l = TLSE_insere(l, n);
    } while(1);

    int pos;
    TLSE *resp = meio(l, &pos);
    if(resp)
        printf("O elemento do meio da lista (info: %d) esta na pos %d\n", resp->info, pos);
    TLSE_libera(l);
    return 0;
}
