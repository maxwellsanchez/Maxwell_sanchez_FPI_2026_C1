#include <stdio.h>

int main() {
    FILE *archivo;
    char linea[1000];
    int max_longitud = 0;
    int i, hay_datos = 0;

    archivo = fopen("arc1.txt", "r");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Leemos linea por linea
    while (fgets(linea, sizeof(linea), archivo)) {
        i = 0;
        // Conteo manual omitiendo el salto de linea final
        while (linea[i] != '\0' && linea[i] != '\n' && linea[i] != '\r') {
            i++;
        }

        if (i > 0) {
            hay_datos = 1;
            if (i > max_longitud) {
                max_longitud = i;
            }
        }
    }

    fclose(archivo);

    if (hay_datos) {
        printf("La longitud de la cadena mas grande es: %d\n", max_longitud);
    } else {
        printf("El archivo esta vacio. Escribe algo en arc1.txt y guardalo.\n");
    }

    return 0;
}
