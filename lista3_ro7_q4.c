#include <stdio.h>
#include <stdlib.h>

int intcmp(int *n1, int *n2){
    if ((*n1)<(*n2)) return -1;
    if ((*n2)<(*n1)) return 1;
    return 0;
}

int main(){
    int n, m;

    while (1){
        int contador = 0, num;
        scanf("%d %d", &n, &m);
        if (n==m && m==0) break;

        int vet[m];

        for (int i=0; i<m; i++) vet[i]=0;

        for (int i=0; i<m; i++)
            scanf("%d", &num);
            vet[num] += 1;
            if (vet[num]==2) contador++;

        printf("%d\n", contador);
    }
}
