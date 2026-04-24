#include <stdio.h>
#include <string.h>

int main() {
    FILE *archivo;
    char cad[50];
    char linea[1000];
    int contador = 0;
    char *ptr;

    printf("Ingresa la cadena a buscar: ");
    scanf("%s", cad);

    archivo = fopen("arc2.txt", "r");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    int len_cad = 0;
    while (cad[len_cad] != '\0') len_cad++;

    while (fgets(linea, sizeof(linea), archivo)) {
        ptr = linea;
        // busca todas las ocurrencias en la linea
        while ((ptr = strstr(ptr, cad)) != NULL) {
            contador++;
            ptr++; // se mueve uno para encontrar traslapes si existen
        }
    }

    fclose(archivo);

    printf("cantidad de caracteres: %d\n", contador);

    return 0;
}
