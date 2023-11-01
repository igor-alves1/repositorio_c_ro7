#include <stdlib.h>
#include <stdio.h>

int main() {
    char str[100];
    int i;
    fgets(str, 99, stdin);

    i = 0;
    while (str[i] != '\n') {
        i++;
    }

    while (i > 0) {
        str[] = str[i];
        i--;
    }

    printf("%s", str);

    return 0;
}
