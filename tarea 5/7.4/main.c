#include <stdio.h>
#include <ctype.h> // para las funciones de letras

int main() {
    char cad[50];
    int i, min = 0, may = 0;

    printf("Dime la frase: ");
    gets(cad); // guardo la frase

    // recorro la cadena hasta el final
    for(i = 0; cad[i] != '\0'; i++) {
        // checo si es minuscula
        if (islower(cad[i])) {
            min++;
        }
        // checo si es mayuscula
        if (isupper(cad[i])) {
            may++;
        }
    }

    printf("Minusculas: %d\n", min);
    printf("Mayusculas: %d\n", may);

    return 0;
}
