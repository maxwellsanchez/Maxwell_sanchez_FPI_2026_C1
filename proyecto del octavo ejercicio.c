#include <stdio.h>

int main() {
    int CLA, CAT, ANT;
    float SAL;

    printf("Clave del trabajador: ");
    scanf("%d", &CLA);
    printf("Categoria (1-4): ");
    scanf("%d", &CAT);
    printf("Antiguedad  (a\xA4os): ");
    scanf("%d", &ANT);
    printf("Salario actual: ");
    scanf("%f", &SAL);

    // Evaluamos con una sola condicion logica grande
    if (((CAT == 3 || CAT == 4) && ANT > 5) || (CAT == 2 && ANT > 7)) {
        printf("\n--- RESULTADO ---\n");
        printf("El trabajador con clave %d REUNE las condiciones para el puesto.\n", CLA);
    } else {
        printf("\n--- RESULTADO ---\n");
        printf("El trabajador con clave %d NO REUNE las condiciones.\n", CLA);
    }

    return 0;
}
