#include <stdio.h>

int main(void) {
    int n, numero, contador = 0;

    scanf("%d", &n);
    numero = n;

    while (contador < n) {
        int primo = 1;

        for (int divisor = 2; divisor < numero; divisor++){
            if ((numero % divisor) == 0) {
                primo = 0;
                break;
            }
        }

        if (primo) {
            printf("%d ", numero);
            contador++;
        }
        numero++;
    }

}
