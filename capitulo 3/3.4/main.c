#include <stdio.h>

int main() {
    float CAL;

    int R1=0, R2=0, R3=0, R4=0, R5=0;

    printf("Ingresa las calificaciones (usa -1 para terminar):\n");
    scanf("%f", &CAL);

    while (CAL != -1) {
        if (CAL < 4) {
            R1++;
        } else if (CAL < 6) {
            R2++;
        } else if (CAL < 8) {
            R3++;
        } else if (CAL < 9) {
            R4++;
        } else {
            R5++;
        }


        scanf("%f", &CAL);
    }

    printf("\n--- Resultados ---");
    printf("\n0..3.99: %d", R1);
    printf("\n4..5.99: %d", R2);
    printf("\n6..7.99: %d", R3);
    printf("\n8..8.99: %d", R4);
    printf("\n9..10  : %d\n", R5);

    return 0;
}
