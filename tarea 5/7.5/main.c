#include <stdio.h>

int main() {
    char cad[50];
    int i = 0; // el contador de la longitud

    printf("Dime la palabra: ");
    gets(cad); // leo la frase

    // mientras no llegue al final
    while (cad[i] != '\0') {
        i++; // sumo uno por cada letra que veo
    }

    printf("La longitud es: %d\n", i); // el total de letras

    return 0;
}
