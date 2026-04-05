#include <stdio.h>

int main() {
    int NUM;

    printf("Ingresa un numero entero: ");
    scanf("%d", &NUM);


    if (NUM == 0) {
        printf("NULO\n");
    }
    else if (NUM % 2 == 0) {
        printf("PAR\n");
    }
    else {
        printf("IMPAR\n");
    }

    return 0;
}
