#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *archivo_lectura, *archivo_escritura;
    char cadenas[500][100]; // maximo 500 cadenas de 100 caracteres
    int i = 0, total_cadenas;

    archivo_lectura = fopen("arc.txt", "r");

    if (archivo_lectura == NULL) {
        perror("Error al abrir arc.txt");
        return 1;
    }

    // leer todas las cadenas y guardarlas en memoria
    while (fscanf(archivo_lectura, "%s", cadenas[i]) != EOF && i < 500) {
        i++;
    }
    total_cadenas = i;
    fclose(archivo_lectura);

    archivo_escritura = fopen("arc_invertido.txt", "w");

    if (archivo_escritura == NULL) {
        perror("Error al crear el archivo de salida");
        return 1;
    }

    // escribir en orden inverso (desde la ultima hasta la primera)
    for (i = total_cadenas - 1; i >= 0; i--) {
        fprintf(archivo_escritura, "%s", cadenas[i]);
        if (i > 0) {
            fprintf(archivo_escritura, " "); // espacio entre palabras
        }
    }

    fclose(archivo_escritura);

    if (total_cadenas > 0) {
        printf("Proceso completado. Revisa 'arc_invertido.txt'.\n");
    } else {
        printf("El archivo original estaba vacio.\n");
    }

    return 0;
}
