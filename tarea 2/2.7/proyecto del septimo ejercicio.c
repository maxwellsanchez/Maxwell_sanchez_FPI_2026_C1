#include <stdio.h>

int main() {
    int tipo, dias, edad;
    float costo_dia, subtotal, total, desc = 0;

    printf("Tipo de tratamiento (1-4): ");
    scanf("%d", &tipo);
    printf("Dias de internacion: ");
    scanf("%d", &dias);
    printf("Edad del cliente: ");
    scanf("%d", &edad);

    // Seleccion de costo por tratamiento
    switch(tipo) {
        case 1: costo_dia = 2800; break;
        case 2: costo_dia = 1950; break;
        case 3: costo_dia = 2500; break;
        case 4: costo_dia = 1150; break;
        default:
            printf("Tipo de tratamiento no valido.\n");
            return 0;
    }

    subtotal = costo_dia * dias;

    //descuentos
    if (edad > 60) {
        desc = 0.25;
        printf("Aplica descuento de Adulto Mayor (25%%)\n");
    }
    else if (edad < 25) {
        desc = 0.15;
        printf("Aplica descuento Juvenil (15%%)\n");
    }
    // exepcion por si no aplica el descuento

    total = subtotal - (subtotal * desc);

    printf("\n--- RESUMEN DE CUENTA ---");
    printf("\nSubtotal: $%.2f", subtotal);
    printf("\nDescuento: $%.2f", subtotal * desc);
    printf("\nTotal a pagar: $%.2f\n", total);

    return 0;
}
