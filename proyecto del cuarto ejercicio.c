#include <stdio.h>
#include <math.h> // Necesaria para la funcion pow()

int main() {
    int T, P, N;
    double lado_izq, lado_der;

    // Entrada de datos
    printf("Ingrese el valor de T: ");
    scanf("%d", &T);
    printf("Ingrese el valor de P: ");
    scanf("%d", &P);
    printf("Ingrese el valor de N: ");
    scanf("%d", &N);

    // Validacion para no dividir por cero
    if (P == 0) {
        printf("Error: P no puede ser cero.\n");
        return 1;
    }

    // Calculo del lado izquierdo: (T / P)^N
    // Convertimos T a float para que la division no sea entera
    lado_izq = pow((double)T / P, N);

    // Calculo del lado derecho: (T^N) / (P^N)
    lado_der = pow(T, N) / pow(P, N);

    // Mostrar resultados intermedios
    printf("\nResultado Lado Izquierdo: %.4f", lado_izq);
    printf("\nResultado Lado Derecho: %.4f\n", lado_der);

    // El Rombo: Comprobacion de igualdad
    if (lado_izq == lado_der) {
        printf("\nRESULTADO: La igualdad se cumple.\n");
    } else {
        printf("\nRESULTADO: La igualdad NO se cumple (posible error de precision).\n");
    }

    return 0;
}
