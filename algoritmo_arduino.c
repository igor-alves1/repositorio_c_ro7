#include <stdio.h>

int main(){
    int n, cnt=0, div=0, j, i;

    scanf("%d", &n);

    while(n>0){
        for(j=1; ; j++){
            for (i=1; i<=j; i++){
                if(j%i==0) div++;
            }
            if (div==2){
                printf("%d", j);
                cnt++;
            }
            if (cnt==n) break;
        }
        scanf("%d", &n);
    }
}
