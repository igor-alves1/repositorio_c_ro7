#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arr_length(char * arr){
    int i, count=0;

    for (i=0; arr[i]!='\0'; i++){
        count++;
    }
    return count;
}


//comentario
void k_str(char *str, int k){
    int n = arr_length(str);

    if (n < 1) {
        return;
    }
    if (k <= 0){
        printf("\n");
        return;
    }
    if (k == 1){
        int i;
        for (i=0; i<n; i++){
            printf("%c ", str[i]);
            k_str(str, k-1);
        }
        return;
    }
}

int main(){
    char igor[10];
    scanf(" %s", igor);

    printf("%d\n", arr_length(igor));
    k_str(igor, 1);

    return 0;
}
