#include <stdio.h>

int main() {
    int DIS, TIE;
    float precio_base, precio_final, dist_total;
    const float PRECIO_KM = 0.19;

    // Entrada de datos
    printf("Ingrese la distancia entre las ciudades (km): ");
    scanf("%d", &DIS);
    printf("Ingrese los dias de estancia: ");
    scanf("%d", &TIE);

    // Cálculos
    dist_total = DIS * 2;
    precio_base = dist_total * PRECIO_KM;

    //descuento
    if (TIE > 10 && dist_total > 500) {
        precio_final = precio_base * 0.80; // Aplica 20% de descuento
        printf("\nSe ha aplicado un descuento del 20%%.\n");
    } else {
        precio_final = precio_base;
        printf("\nNo aplica descuento.\n");
    }

    // Resultado
    printf("El precio total del billete es: $%.2f\n", precio_final);

    return 0;
}
