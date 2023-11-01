#include <stdio.h>
#include <stdlib.h>

void retira_mult_k(int * vet, int n, int * novo_tam_vet, int k){
    int i;
    vet = malloc(sizeof(int)*n);
    int * p1 = novo_tam_vet;

    vet = malloc(sizeof(int)*n);
    for (i=0; i< n; i++){
        printf("%d", vet[i]);
    }

    for (i=0; i < n; i++){
        if (vet[i]%k == 0){
            (*p1) -= 1;
        }
    }
    printf("%d", (*p1));
    vet = realloc(vet, (*p1));
}

int main(){
    int vet[] = {2, 3, 5, 4, 6, 8, 7, 9, 1};
    int k, n=9, novo_tam = n;

    retira_mult_k(vet, n, &novo_tam, k);

    for (int i = 0; i < novo_tam; i++){
        printf("%d ", vet[i]);
    }

    return 0;

}
