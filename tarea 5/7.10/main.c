#include <stdio.h>

int main() {
    char FRA[20][50];
    int n, i, j, largo, max = -1, pos_max = 0;

    printf("Cuantas frases vas a meter (max 20): ");
    scanf("%d", &n);
    getchar(); // limpio el enter

    for (i = 0; i < n; i++) {
        printf("Frase %d: ", i + 1);
        gets(FRA[i]); // guardo en el arreglo bidimensional
    }

    // recorro cada cadena guardada
    for (i = 0; i < n; i++) {
        largo = 0;
        // cuento sin usar strlen
        while (FRA[i][largo] != '\0') {
            largo++;
        }

        // comparo para ver si es la mas larga
        if (largo > max) {
            max = largo;
            pos_max = i; // guardo cual fila era
        }
    }

    printf("\nLa cadena mas larga es: %s\n", FRA[pos_max]);
    printf("Tiene %d caracteres\n", max);

    return 0;
}
