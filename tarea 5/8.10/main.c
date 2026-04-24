#include <stdio.h>
#include <string.h>

typedef struct {
    int clave;
    char nombre[50];
    int existencia;
} PRODUCTO;

int buscar_producto(PRODUCTO tienda[], int n, int clave) {
    for (int i = 0; i < n; i++) {
        if (tienda[i].clave == clave) return i;
    }
    return -1;
}

int main() {
    PRODUCTO tienda[100];
    int n, i, clave_buscada, cantidad;
    char operacion;

    printf("Cantidad de productos diferentes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nProducto %d\n", i + 1);
        printf("Clave: ");
        scanf("%d", &tienda[i].clave);
        getchar();
        printf("Nombre: ");
        gets(tienda[i].nombre);
        printf("Existencia inicial: ");
        scanf("%d", &tienda[i].existencia);
    }

    printf("\n--- Registro de Transacciones ---\n");
    printf("Formato: [C/V] [Clave] [Cantidad]. Fin con '0 0 0'\n");

    while (1) {
        scanf(" %c", &operacion);
        if (operacion == '0') break;

        scanf("%d %d", &clave_buscada, &cantidad);
        int pos = buscar_producto(tienda, n, clave_buscada);

        if (pos != -1) {
            if (operacion == 'C' || operacion == 'c') {
                tienda[pos].existencia += cantidad;
                printf("Compra registrada. Nueva existencia: %d\n", tienda[pos].existencia);
            } else if (operacion == 'V' || operacion == 'v') {
                if (tienda[pos].existencia >= cantidad) {
                    tienda[pos].existencia -= cantidad;
                    printf("Venta registrada. Nueva existencia: %d\n", tienda[pos].existencia);
                } else {
                    printf("Error: Existencia insuficiente (%d disponibles).\n", tienda[pos].existencia);
                }
            } else {
                printf("Operacion no valida.\n");
            }
        } else {
            printf("Clave de producto no encontrada.\n");
        }
    }

    printf("\n--- Inventario Actualizado ---\n");
    printf("%-10s | %-20s | %-10s\n", "CLAVE", "NOMBRE", "EXISTENCIA");
    for (i = 0; i < n; i++) {
        printf("%-10d | %-20s | %-10d\n",
               tienda[i].clave, tienda[i].nombre, tienda[i].existencia);
    }

    return 0;
}
