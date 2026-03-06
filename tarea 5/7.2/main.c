#include <stdio.h>
#include <stdlib.h> // para atof

int main() {
    char cad[10];
    char s = 'S'; // para el si o no
    float num, suma = 0;
    int cuenta = 0;

    // mientras el usuario quiera seguir
    while (s == 'S' || s == 's') {
        printf("Deseas ingresar una cadena? (S/N): ");
        scanf(" %c", &s); // el espacio es para el buffer

        if (s == 'S' || s == 's') {
            printf("numero/s: ");
            scanf("%s", cad); // leo la cadena

            num = atof(cad); // convierto texto a real
            suma = suma + num;
            cuenta++; // llevo el conteo para el promedio
        }
    }

    // si metio algo saco cuentas
    if (cuenta > 0) {
        printf("Suma: %.2f\n", suma);
        printf("Promedio: %.2f\n", suma / cuenta);
    } else {
        printf("No pusiste nada.\n");
    }

    return 0;
}
