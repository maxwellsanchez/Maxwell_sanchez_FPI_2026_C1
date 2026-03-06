#include <stdio.h>
#include <stdlib.h>

int main() {
    char cad[50];
    int i, j, repeticiones;

    printf("Ingresa la cadena (ejemplo 3p6c): ");
    scanf("%s", cad); // leo la entrada

    // avanzo de dos en dos porque es numero-letra
    for (i = 0; cad[i] != '\0'; i += 2) {

        // convierto el char del numero a entero restando '0'
        repeticiones = cad[i] - '0';

        // este ciclo imprime la letra de al lado
        for (j = 0; j < repeticiones; j++) {
            printf("%c", cad[i+1]);
        }
    }

    printf("\n"); // salto de linea al final

    return 0;
}
