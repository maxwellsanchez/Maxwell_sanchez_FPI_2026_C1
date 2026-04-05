#include <stdio.h>
#include <string.h>

#define MAX 100

// Definición de la estructura
typedef struct {
    int clave;
    char nombre[50];
    int existencia;
    float precio;
} PRODUCTO;

// Prototipos de funciones
void Ventas(PRODUCTO INV[], int n);
void Reabastecimiento(PRODUCTO INV[], int n);
int NuevosProductos(PRODUCTO INV[], int n);
void MostrarInventario(PRODUCTO INV[], int n);
int Buscar(PRODUCTO INV[], int n, int clave);

int main() {
    PRODUCTO INV[MAX];
    int n = 0; // Cantidad actual de productos
    int opcion;

    do {
        printf("\n--- SISTEMA DE INVENTARIO ---\n");
        printf("1. Nuevos Productos (Altas)\n");
        printf("2. Ventas\n");
        printf("3. Reabastecimiento\n");
        printf("4. Mostrar Inventario\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: n = NuevosProductos(INV, n); break;
            case 2: Ventas(INV, n); break;
            case 3: Reabastecimiento(INV, n); break;
            case 4: MostrarInventario(INV, n); break;
        }
    } while(opcion != 0);

    return 0;
}

// a) Módulo de Ventas
void Ventas(PRODUCTO INV[], int n) {
    int clave, cant, pos;
    float totalVenta = 0;

    printf("\n--- REGISTRO DE VENTAS ---\n");
    while (1) {
        printf("Clave del producto (0 para terminar): ");
        scanf("%d", &clave);
        if (clave == 0) break;

        pos = Buscar(INV, n, clave);
        if (pos != -1) {
            printf("Cantidad a vender: ");
            scanf("%d", &cant);
            if (cant <= INV[pos].existencia) {
                INV[pos].existencia -= cant;
                totalVenta += (cant * INV[pos].precio);
                printf("Venta registrada.\n");
            } else {
                printf("Error: Existencia insuficiente (%d disponibles).\n", INV[pos].existencia);
            }
        } else {
            printf("Producto no encontrado.\n");
        }
    }
    printf("Total de la venta al cliente: $%.2f\n", totalVenta);
}

// b) Módulo de Reabastecimiento
void Reabastecimiento(PRODUCTO INV[], int n) {
    int clave, cant, pos;
    printf("\n--- REABASTECIMIENTO ---\n");
    while (1) {
        printf("Clave del producto (0 para terminar): ");
        scanf("%d", &clave);
        if (clave == 0) break;

        pos = Buscar(INV, n, clave);
        if (pos != -1) {
            printf("Cantidad recibida: ");
            scanf("%d", &cant);
            INV[pos].existencia += cant;
            printf("Inventario actualizado.\n");
        } else {
            printf("Error: El producto no existe. Use 'Nuevos Productos' para registrarlo.\n");
        }
    }
}

// c) Módulo de Nuevos Productos (Mantiene el orden)
int NuevosProductos(PRODUCTO INV[], int n) {
    int clave, i, j;
    while (n < MAX) {
        printf("\nNueva clave de producto (0 para terminar): ");
        scanf("%d", &clave);
        if (clave == 0) break;

        // Encontrar posición para mantener el orden (Insertion Sort logic)
        i = 0;
        while (i < n && INV[i].clave < clave) {
            i++;
        }

        // Desplazar elementos a la derecha
        for (j = n; j > i; j--) {
            INV[j] = INV[j-1];
        }

        // Insertar nuevo producto
        INV[i].clave = clave;
        printf("Nombre: ");
        scanf("%s", INV[i].nombre);
        printf("Existencia: ");
        scanf("%d", &INV[i].existencia);
        printf("Precio unitario: ");
        scanf("%f", &INV[i].precio);

        n++;
    }
    return n;
}

// d) Módulo de Inventario
void MostrarInventario(PRODUCTO INV[], int n) {
    printf("\n%-10s %-20s %-12s %-10s\n", "CLAVE", "NOMBRE", "EXISTENCIA", "PRECIO");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-20s %-12d $%-10.2f\n", INV[i].clave, INV[i].nombre, INV[i].existencia, INV[i].precio);
    }
}

// Función auxiliar de búsqueda binaria
int Buscar(PRODUCTO INV[], int n, int clave) {
    int izq = 0, der = n - 1, centro;
    while (izq <= der) {
        centro = (izq + der) / 2;
        if (INV[centro].clave == clave) return centro;
        if (clave < INV[centro].clave) der = centro - 1;
        else izq = centro + 1;
    }
    return -1;
}
