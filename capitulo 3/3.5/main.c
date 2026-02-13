#include <stdio.h>

int main() {
    int N;

    printf("Ingresa un entero positivo: ");
    scanf("%d", &N);

    printf("Sucesion de ULAM: ");

    while (N != 1) {
        printf("%d, ", N);

        if (N % 2 == 0) {
            N = N / 2;
        } else {
            N = (N * 3) + 1;
        }
    }

    printf("1\n");

    return 0;
}
