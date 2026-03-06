#include <stdio.h>
#include <string.h>

int main() {
    char cad0[50], cad1[50];
    int i, j, coincidencia, cuenta = 0;
    int n, m;

    printf("Dime la cadena larga: ");
    gets(cad0); // leo la frase completa
    printf("Dime la que buscas: ");
    gets(cad1); // leo lo que quiero buscar

    n = strlen(cad0); // tamaño de la primera
    m = strlen(cad1); // tamaño de la que busco

    // recorro la cadena larga
    for (i = 0; i <= n - m; i++) {
        coincidencia = 1; // supongo que si esta

        // comparo pedacito por pedacito
        for (j = 0; j < m; j++) {
            if (cad0[i + j] != cad1[j]) {
                coincidencia = 0; // no era igual
                break;
            }
        }

        if (coincidencia == 1) {
            cuenta++; // si la encontre sumo uno
        }
    }

    printf("Se encontro: %d veces\n", cuenta);

    return 0;
}
