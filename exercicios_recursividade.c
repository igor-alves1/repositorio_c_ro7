#include <stdio.h>
#include <stdlib.h>

int euclides(int a, int b){
    if (a==0) return b;
    if (b==0) return a;

    int max, min;
    if (a>b){
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }


    return euclides(min, max%min);
}

int main(){
    int y = 81, z = 27;
    printf("%d", euclides(y, z));

}

    return 0;

