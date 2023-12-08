#include <stdio.h>
#include <stdlib.h>
#include "TLSE.h"
#include "TP.h"

TP *merge(TP **vetp, int n){
    TP **vet_aux = (TP **)malloc(sizeof(TP *)*n);
    TP *pilha = TP_inicializa();
    printf("ok!");
    for (int i=0; i<n; i++){
        while (!TP_vazia(vetp[i]))
            int elem = TP_pop(vetp[i]);
            TP_push(vet_aux[i], elem);
        TP_imprime(vet_aux[i]);
        printf("\n");
    }
    int flag = 1;
    while (flag){
        int maior = -1, indice, contador = 0;
        for(int i=0; i<n; i++){
            if(TP_vazia(vet_aux[i]))
                continue;
            int num = TP_pop(vet_aux[i]);
            TP_push(vet_aux[i], num);
            if(num>maior){
                maior = num;
                indice = i;
            }
        }
        TP_push(pilha, maior);
        TP_push(vetp[indice], maior);
        for(int j=0; j<n; j++){
            if(TP_vazia(vetp[j])) contador++;
        }
        if(contador==n) flag = 0;
    }
    for(int i=0; i<n; i++){
        TP_imprime(vet_aux[i]);
        printf("\n");
        free(vet_aux[i]);
    }
    free(vet_aux);
    return pilha;
}

int main()
{
    int n;
    printf("Digite o numero de pilhas... ");
    scanf("%d", &n);
    if (n<=0) return 0;

    TP **vetp = (TP **) malloc(sizeof(TP*)*n);
    int i;
    for(i = 0; i<n; i++)
        vetp[i] = TP_inicializa();

    i=0;
    while(i<n){
        printf("Digite a pilha %d em ordem decrescente... Quando for fornecido um elemento fora de ordem, a pilha nao recebera mais elementos...\n", i+1);
        int ant;
        scanf("%d", &ant);
        TP_push(vetp[i], ant);
        while(1){
            int aux;
            scanf("%d", &aux);
            if (aux>ant) break;
            TP_push(vetp[i], aux);
            ant = aux;
        }
        i++;
    }
    TP *resp = merge(vetp, n);
    TP_imprime(resp);
    TP_libera(resp);
    for(i=0; i<n; i++) TP_libera(vetp[i]);
    free(vetp);
    return 0;
}
