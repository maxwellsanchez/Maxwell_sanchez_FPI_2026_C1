#include <stdio.h>

int main() {
    int num;
    long factorial = 1;

    printf("Ingrese el numero por favor: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("\nError: No se puede calcular el factorial de un negativo.\n");
    }
    else {


        for (int i = 1; i <= num; i++) {
            factorial *= i;
        }

        // 4. Resultado final
        printf("\nEl factorial de %d es: %ld\n", num, factorial);
    }

    return 0;
}
