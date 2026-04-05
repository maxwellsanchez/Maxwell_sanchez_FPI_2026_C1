#include <stdio.h>

int main() {
    int N, NUM, I;
    int SUMPAR = 0;
    float SUMIMP = 0;
    int CONTIMP = 0;

    printf("¿Cuantos numeros vas a ingresar?: ");
    scanf("%d", &N);

    for (I = 1; I <= N; I++) {
        printf("Ingresa el numero %d: ", I);
        scanf("%d", &NUM);

        if (NUM % 2 == 0) {

            SUMPAR = SUMPAR + NUM;
        } else {

            SUMIMP = SUMIMP + NUM;
            CONTIMP++;
        }
    }

    printf("\nSuma de los pares: %d", SUMPAR);

    if (CONTIMP > 0) {
        printf("\nPromedio de los impares: %.2f\n", SUMIMP / CONTIMP);
    } else {
        printf("\nNo se ingresaron numeros impares.\n");
    }

    return 0;
}
