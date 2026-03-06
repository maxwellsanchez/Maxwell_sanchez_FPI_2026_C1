#include <stdio.h>
#include <string.h>

int main() {
    char FRA[20][30];
    char temp[30]; // para el intercambio
    int n, i;

    printf("Cuantas cadenas vas a meter: ");
    scanf("%d", &n);
    getchar(); // quito el salto de linea

    // llenado del arreglo
    for (i = 0; i < n; i++) {
        printf("Cadena %d: ", i + 1);
        gets(FRA[i]);
    }

    // ciclo para voltear las filas
    for (i = 0; i < n / 2; i++) {
        // muevo la primera a temporal
        strcpy(temp, FRA[i]);
        // muevo la ultima a la primera
        strcpy(FRA[i], FRA[n - 1 - i]);
        // muevo temporal a la ultima
        strcpy(FRA[n - 1 - i], temp);
    }

    printf("\nResultado del intercambio:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", FRA[i]);
    }

    return 0;
}
