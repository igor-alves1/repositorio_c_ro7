#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    float X[10], media, d, soma, somatorio, parcela;
    int i;
    somatorio = soma = 0;

    printf("Digite os 10 elementos do vetor: ");
    for (i = 0; i < 10; i++) {
        scanf("%f", &X[i]);
        soma += X[i];
    }

    media = soma/10;

    for (i = 0; i < 10; i++){
        parcela = X[i] - media;
        somatorio += parcela;
    }

    d = sqrt(somatorio/9);
    printf("media: %f, somatorio: %f\n", media, somatorio);
    printf("O desvio padrao e igual a %f", d);

    return 0;
}
