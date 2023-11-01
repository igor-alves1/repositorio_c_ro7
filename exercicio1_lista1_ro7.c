#include <stdio.h>

int main(void) {
    int n, numero = 2, contador = 0;

    scanf("%d", &n);

    while (contador < n) { // executa para todos os n primeiros n�meros primos
        int primo = 1; // flag que controla se um n�mero � primo ou n�o

        for (int divisor = 2; divisor < numero; divisor++){ // loop que procura por divisores
            if ((numero % divisor) == 0) { // se um divisor for encontrado, interrompe o loop imediatamente
                primo = 0; // a flag recebe o valor falso
                break;
            }
        }

        if (primo) { // se o numero for primo, � impresso na tela
            printf("%d ", numero);
            contador++;
        }
        numero++;
    }

}
