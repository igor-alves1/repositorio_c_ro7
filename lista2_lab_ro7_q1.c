#include <stdio.h>
#include <stdlib.h>

int *mat2vet(int **mat, int lin, int col){
    int *vet;
    vet = (int *)malloc(sizeof(int)*lin*col);

    for (int i=0; i<lin*col; i++){
        vet[i] = mat[i/col][i%col];
    }

    return vet;
}

int main(){
    int **matriz, linhas, colunas, *vet;

    scanf("%d%d", &linhas, &colunas);

    matriz = (int **)malloc(sizeof(int *)*linhas);
    for (int i=0; i<linhas; i++){
        matriz[i] = (int *)malloc(sizeof(int)*colunas);
    }

    for(int i=0; i<linhas; i++){
        for (int j=0; j<colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    vet = mat2vet(matriz, linhas, colunas);
    for (int i=0; i<linhas; i++){
        free(matriz[i]);
    }
    free(matriz);

    for (int item=0; item<linhas*colunas; item++)
        printf("%d ", vet[item]);
    free(vet);

    return 0;
}
