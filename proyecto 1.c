#include <stdio.h>
#include <math.h>

int main() {
    int R, T, Q;
    double resultado;

    printf("Ingresa R, T y Q separados por espacio: ");
    if (scanf("%d %d %d", &R, &T, &Q) != 3) return 1;

    // Operacion: R^4 - T^3 + 4*Q^2
    resultado = pow(R, 4) - pow(T, 3) + (4 * pow(Q, 2));

    if (resultado < 820) {
        printf("\nLOS VALORES SATISFACEN LA EXPRESION:\n");
        printf("R: %d, T: %d, Q: %d\n", R, T, Q);
    } else {
        printf("\nNo se cumple la condicion (Resultado: %.2f)\n", resultado);
    }

    return 0;
}
