#include <stdio.h>
#include <stdlib.h>

typedef struct pilha TP;
TP *TP_inicializa(void);
void TP_push(TP *pilha, int elem);
int TP_pop(TP *pilha);
void TP_libera(TP *pilha);
int TP_vazia(TP *pilha);
