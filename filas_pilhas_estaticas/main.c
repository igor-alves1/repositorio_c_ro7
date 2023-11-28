#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    TP *pilha = TP_inicializa();
    int num;

    for(int i=0; i< 5; i++){
        scanf("%d", &num);
        TP_push(pilha, num);
    }
    printf("%d\n", TP_pop(pilha));
    TP_push(pilha, 99);
    printf("%d", TP_pop(pilha));
    TP_libera(pilha);
    return 0;
}
