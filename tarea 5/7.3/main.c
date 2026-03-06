#include <stdio.h>
#include <ctype.h> // para islower

int main() {
    char cad[50];
    int n;

    printf("Escribe la frase o palabra: ");
    gets(cad); // leo la frase completa

    printf("Cual posicion quieres ver: ");
    scanf("%d", &n); // guardo el numero

    // checo si el caracter en n es minuscula
    if (cad[n] >= 'a' && cad[n] <= 'z') {
        printf("Si es minuscula\n");
    } else {
        printf("No es minuscula\n");
    }

    return 0;
}
