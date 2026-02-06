#include <stdio.h>
#include <math.h>

int main() {
    int Y;
    float X;

    printf("Ingresa el valor de Y: ");
    scanf("%d", &Y);

    // Primera condicion
    if (Y >= 0 && Y <= 10) {
        if (Y == 0) {
            printf("Error: Division por cero.\n");
            X = 0;
        } else {
            X = (4.0 / Y) - Y;
        }
    }
    // Segunda condicion
    else if (Y >= 11 && Y <= 25) {
        X = pow(Y, 3) - 12;
    }
    // Tercera condicion
    else if (Y >= 26 && Y <= 50) {
        X = pow(Y, 2) + pow(Y, 3) - 18;
    }

    else {
        X = 0;
    }

    // Impresion
    printf("\nValor de Y: %d", Y);
    printf("\nValor de X (F(Y)): %.2f\n", X);

    return 0;
}
