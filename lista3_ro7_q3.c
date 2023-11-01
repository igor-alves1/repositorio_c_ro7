#include <stdio.h>
#include <stdlib.h>

int strcmp(char *s1, char *s2){
    if ((!s1[0])&&(!s2[0])) return 0;
    if (!s1[0] || (s1[0]>s2[0])) return -1;
    if (!s2[0] || (s1[0]<s2[0])) return 1;
    return 0;
}

int main(){
    int i=0;
    char str1[8], str2[8];

    scanf("%7[^\n]", str1);
    scanf("%7[^\n]", str2);
    while(str1[i] != "\0") {
        printf("%c ", str1[i]);
        i++;
    }

    qsort(str1, 8, sizeof(char), strcmp);
    qsort(str2, 8, sizeof(char), strcmp);

    while(str1[i] != "\0") {
        printf("%c ", str1[i]);
        i++;
    }
    return 0;
}
