#include <stdio.h>
#include <string.h>

int main() {
    char fra[50];
    int i, n;

    printf("Escribe la frase: ");
    gets(fra); // leo la linea completa

    n = strlen(fra); // saco el tamaño total

    printf("Al reves: ");
    // empiezo desde el final hasta la posicion 0
    for (i = n - 1; i >= 0; i--) {
        printf("%c", fra[i]); // imprimo caracter por caracter
    }

    printf("\n"); // un salto para que se vea bien

    return 0;
}
