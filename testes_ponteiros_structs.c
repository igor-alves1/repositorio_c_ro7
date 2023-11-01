#include <stdio.h>
#include <stdlib.h>

typedef struct prod{
    char misc[51];
    float preco;
} TPROD;

int main(){
    TPROD igor, *pigor = &igor;
    scanf(" %50[^\n]", pigor->misc);
    scanf("%f", &pigor->preco);

    printf("%c", pigor->misc[8]);
    printf("%f", pigor->preco);

    return 0;
}
