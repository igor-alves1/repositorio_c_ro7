#include <stdio.h>
#include <stdlib.h>

typedef struct prod{
    char misc[51];
    float preco;
} TPROD;

int misc_cmp(TPROD **p1, TPROD **p2){
    TPROD *pprod1 = *(p1), *pprod2 = *(p2);

    int i = 8;
    // ordenacao nome
    while (i<51){
        if (!(pprod1->misc[i]) && !(pprod2->misc[i])) break;
        if (!(pprod1->misc[i])) return -1;
        if (!(pprod2->misc[i])) return 1;
        if ((pprod1->misc[i]) > (pprod2->misc[i])) return 1;
        if ((pprod1 ->misc[i]) < (pprod2->misc[i])) return -1;
        i++;
    }

    //ordenacao data
    for (i=4; i<8; i++){
        if ((pprod1->misc[i]) > (pprod2->misc[i])) return 1;
        if ((pprod1 ->misc[i]) < (pprod2->misc[i])) return -1;
    }
    for (i=2; i<4; i++){
        if ((pprod1->misc[i]) > (pprod2->misc[i])) return 1;
        if ((pprod1 ->misc[i]) < (pprod2->misc[i])) return -1;
    }
    for (i=0; i<2; i++){
        if ((pprod1->misc[i]) > (pprod2->misc[i])) return 1;
        if ((pprod1 ->misc[i]) < (pprod2->misc[i])) return -1;
    }
    if (pprod1->preco > pprod2->preco) return -1;
    if (pprod1->preco < pprod2->preco) return 1;

    return 0;
}

int ordena_a(TPROD **vet, int n){
    qsort(vet, n, sizeof(TPROD*), misc_cmp);
}

int main(void){
    int n;
    do{
        scanf("%d", &n);
        if(n > 0)break;
    }while(1);

    TPROD **vet = (TPROD **) malloc(sizeof(TPROD *) * n);
    int i;
    for(i = 0; i < n; i++){
        vet[i] = (TPROD *) malloc(sizeof(TPROD));
        scanf(" %50[^\n]", vet[i]->misc);
        scanf("%f", &vet[i]-> preco);
    }
    ordena_a(vet, n);

    for(i = 0; i < n; i++){
        printf("%s\t%f\n", vet[i]->misc, vet[i]-> preco);
        free(vet[i]);
    }
    free(vet);

    return 0;
}
