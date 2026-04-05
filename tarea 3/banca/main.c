#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int j1, j2, j3;
    int r1, r2, r3;
    int aciertos = 0;

    srand(time(NULL));

    printf("--- BIENVENIDO A BANCA Loteca ---\n");
    printf("Ingrese 3 numeros (10-40) (separados por espacio): ");
    scanf("%d %d %d", &j1, &j2, &j3);

    r1 = 10 + rand() % 31;
    r2 = 10 + rand() % 31;
    r3 = 10 + rand() % 31;

    printf("\nNumeros ganadores: %d - %d - %d", r1, r2, r3);

    if (j1 == r1) aciertos++;
    if (j2 == r2) aciertos++;
    if (j3 == r3) aciertos++;

    printf("\n---------------------------------------");
    if (aciertos == 3) {
        printf("\n¡INCREIBLE! Gano el premio mayor.");
    } else if (aciertos > 0) {
        printf("\nFelicidades, tuvo %d acierto(s).", aciertos);
    } else {
        printf("\nNo hubo suerte esta vez. ¡Sigue intentando!");
    }
    printf("\n---------------------------------------\n");

    return 0;
}
