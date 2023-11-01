#include <stdio.h>

int main(void){
    int h1, m1, h2, m2, total_min, total_dia;
    total_dia = 24*60;

    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);

    if ((h1 <= h2) && (m1 <= m2)) {
        total_min = 60*(h2 - h1) + (m2 - m1);
    } else {
        total_min = total_dia - (60*h1 + m1);
        total_min += h2*60 + m2;
    }

    printf("%d", total_min);
}
