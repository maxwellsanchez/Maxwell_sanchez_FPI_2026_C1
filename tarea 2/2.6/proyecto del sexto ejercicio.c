#include <stdio.h>

int main() {
    int CLA;
    float DUR, PRE, COSTO;

    // Pedimos los datos
    printf("Ingrese la clave de la zona: ");
    scanf("%d", &CLA);
    printf("Ingrese la duracion de la llamada (minutos): ");
    scanf("%f", &DUR);

    // Seleccionamos el precio segun la clave
    switch(CLA) {
        case 1:  PRE = 0.13; break;
        case 2:  PRE = 0.11; break;
        case 5:  PRE = 0.22; break;
        case 6:  PRE = 0.19; break;
        case 7:  PRE = 0.17; break;
        case 9:  PRE = 0.17; break;
        case 10: PRE = 0.20; break;
        case 15: PRE = 0.39; break;
        case 20: PRE = 0.28; break;
        default:
            PRE = -1; // Usamos esto para detectar una clave falsa
            printf("\nError: La clave ingresada no existe.\n");
    }

    // Si la clave fue valida, calculamos el total
    if (PRE != -1) {
        COSTO = DUR * PRE;
        printf("\nEl costo total de la llamada es: $%.2f\n", COSTO);
    }

    return 0;
}
