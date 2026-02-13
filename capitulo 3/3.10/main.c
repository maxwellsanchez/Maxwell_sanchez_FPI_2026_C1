#include <stdio.h>

int main() {
    int I, J, SUM, C;
    int CANT_PERFECTOS = 0;

    printf("Ingrese el numero limite: ");
    scanf("%d", &C);

    printf("Numeros perfectos encontrados:\n");

    for (I = 1; I <= C; I++) {
        SUM = 0;

        for (J = 1; J <= (I / 2); J++) {
            if (I % J == 0) {
                SUM = SUM + J;
            }
        }

        if (SUM == I && I != 0) {
            printf("%d ", I);
            CANT_PERFECTOS++;
        }
    }

    printf("\nTotal de numeros perfectos en el intervalo: %d\n", CANT_PERFECTOS);

    return 0;
}
