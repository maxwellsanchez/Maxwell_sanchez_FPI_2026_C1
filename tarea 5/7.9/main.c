#include <stdio.h>
#include <string.h>

int main() {
    char fra[50];
    int i, palabras = 0;

    printf("Escribe la frase: ");
    gets(fra); // guardo la frase completa

    // si la frase no esta vacia al menos hay una palabra
    if (strlen(fra) > 0) {
        palabras = 1;
    }

    // recorro buscando espacios
    for (i = 0; fra[i] != '\0'; i++) {
        // si hay un espacio cuento otra palabra
        if (fra[i] == ' ') {
            palabras++;
        }
    }

    printf("Hay %d palabras\n", palabras);

    return 0;
}
