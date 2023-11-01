#include <stdio.h>
int primo(int a){
    if (a==1) return 0;
    if (a==2) return 1;

    for(int i = 0; i < a/2; i++){
       if(a%i == 0){
        return 0;
       }
    }
    return 1;
}
int main(void){
    int c;
    scanf("%d", &c);
    int mortos[c];
    for(int i = 0; i < c; i++){
        mortos[i] = 0;
    }
    int mor = 0;
    int m = 1;
    while(mor < c-1){
        if(primo(m) && !mortos[m%c]){
            mortos[m%c-1] = 1;
            mor++;
        }
        m++;
    }
    for(int i =0; i<c; i++){
        if(!mortos[i]){
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
