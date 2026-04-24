#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *archivo;
    char caracter;
    int contador = 0;
    int en_palabra = 0;

    archivo = fopen("arc.txt", "r");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    while ((caracter = fgetc(archivo)) != EOF) {
        // Detecta si el caracter no es un espacio, salto de linea o tabulacion
        if (!isspace(caracter)) {
            if (!en_palabra) {
                en_palabra = 1;
                contador++;
            }
        } else {
            en_palabra = 0;
        }
    }

    fclose(archivo);

    if (contador > 0) {
        printf("hay %d palabras.\n", contador);
    } else {
        printf("El archivo esta vacio.\n");
    }

    return 0;
}
