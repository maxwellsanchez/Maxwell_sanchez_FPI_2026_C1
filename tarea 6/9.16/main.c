#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *archivo;
    char c;
    char anterior = ' ';
    int errores = 0;

    archivo = fopen("doc.dat", "r");

    if (archivo == NULL) {
        perror("Error al abrir doc.dat");
        return 1;
    }

    while ((c = fgetc(archivo)) != EOF) {
        char actual = tolower(c);
        char ant = tolower(anterior);

        // Regla: antes de b va m, no n
        if (actual == 'b' && ant == 'n') {
            printf("Error ortografico: 'nb' detectado. Debe ser 'mb'.\n");
            errores++;
        }

        // Regla: antes de p va m, no n
        if (actual == 'p' && ant == 'n') {
            printf("Error ortografico: 'np' detectado. Debe ser 'mp'.\n");
            errores++;
        }

        // Regla: antes de v va n, no m
        if (actual == 'v' && ant == 'm') {
            printf("Error ortografico: 'mv' detectado. Debe ser 'nv'.\n");
            errores++;
        }

        anterior = c;
    }

    fclose(archivo);

    if (errores == 0) {
        printf("No se encontraron errores en las reglas especificadas.\n");
    } else {
        printf("\nTotal de errores encontrados: %d\n", errores);
    }

    return 0;
}
