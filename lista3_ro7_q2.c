#include <stdio.h>
#include <stdlib.h>

int main(){
    int grau;

    printf("Diga a ordem do polinômio: ");
    scanf("%d", &grau);

    int coefs[grau+1], coefs_derivada[grau], coefs_integral[grau];

    for (int i=0; i<grau+1; i++){
        scanf("%d", &coefs[i]);
    }

    printf("Derivada: \n");
    for (int j=0; j<grau; j++){
        coefs_derivada[j] = coefs[j+1]*(j+1);
        printf("%d ", coefs_derivada[j]);
    }

    printf("\nIntegral:\n");
    printf("0 ");
    for (int j=0; j<grau+1; j++){
        coefs_integral[j] = coefs[j]/(j+1);
        printf("%d ", coefs_integral[j]);
    }

    return 0;
}
