#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *archivo;
    char caracter;
    int a = 0, e = 0, i = 0, o = 0, u = 0;

    archivo = fopen("arc.txt", "r");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    while ((caracter = fgetc(archivo)) != EOF) {
        // convertir a minuscula para contar ambas (A/a)
        caracter = tolower(caracter);

        switch (caracter) {
            case 'a': case 'á': a++; break;
            case 'e': case 'é': e++; break;
            case 'i': case 'í': i++; break;
            case 'o': case 'ó': o++; break;
            case 'u': case 'ú': u++; break;
        }
    }

    fclose(archivo);

    printf("a: %d\n", a);
    printf("e: %d\n", e);
    printf("i: %d\n", i);
    printf("o: %d\n", o);
    printf("u: %d\n", u);

    return 0;
}
