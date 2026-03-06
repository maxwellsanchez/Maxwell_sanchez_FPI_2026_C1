#include <stdio.h>
#include <string.h>

// Programa para contar letras
int main() {
    char cad[50];
    char car;
    int i, cuenta = 0; // cuenta es el acumulador

    printf("Escribe la frase: ");
    gets(cad); // lector de la cadena

    printf("Que letra quieres buscar: ");
    scanf("%c", &car);

    // bucle para revisar letra por letra
    for(i = 0; i < strlen(cad); i++) {
        if (cad[i] == car) {
            cuenta++; // si es igual sumo uno
        }
    }

    printf("Resultado: %d\n", cuenta);

    return 0;
}
