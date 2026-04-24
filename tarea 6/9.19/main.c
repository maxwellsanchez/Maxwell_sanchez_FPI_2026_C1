#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int clave;
    char nombre[50];
    int existencia;
    float precio;
} PRODUCTO;

void ventas();
void reabastecimiento();
void nuevos_productos();
void inventario();

int main() {
    int opcion;
    do {
        printf("\n--- COMERCIALIZADORA MONTERREY ---\n");
        printf("1. Ventas\n2. Reabastecimiento\n3. Nuevos Productos\n4. Ver Inventario\n5. Salir\n");
        printf("Seleccione: ");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1: ventas(); break;
            case 2: reabastecimiento(); break;
            case 3: nuevos_productos(); break;
            case 4: inventario(); break;
        }
    } while(opcion != 5);
    return 0;
}

void ventas() {
    FILE *arch = fopen("com.dat", "rb+");
    int clave, cant;
    float total = 0;
    PRODUCTO p;
    if (!arch) return;

    printf("Ingrese Clave y Cantidad (0 para terminar):\n");
    while (scanf("%d", &clave) && clave != 0) {
        scanf("%d", &cant);
        rewind(arch);
        int encontrado = 0;
        while (fread(&p, sizeof(PRODUCTO), 1, arch)) {
            if (p.clave == clave) {
                if (p.existencia >= cant) {
                    p.existencia -= cant;
                    total += (p.precio * cant);
                    fseek(arch, -(long)sizeof(PRODUCTO), SEEK_CUR);
                    fwrite(&p, sizeof(PRODUCTO), 1, arch);
                    printf("Vendido: %s\n", p.nombre);
                } else printf("Existencia insuficiente.\n");
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) printf("Producto no existe.\n");
    }
    printf("Total Venta: %.2f\n", total);
    fclose(arch);
}

void reabastecimiento() {
    FILE *arch = fopen("com.dat", "rb+");
    int clave, cant;
    PRODUCTO p;
    if (!arch) return;

    printf("Clave y Cantidad a sumar (0 para terminar):\n");
    while (scanf("%d", &clave) && clave != 0) {
        scanf("%d", &cant);
        rewind(arch);
        while (fread(&p, sizeof(PRODUCTO), 1, arch)) {
            if (p.clave == clave) {
                p.existencia += cant;
                fseek(arch, -(long)sizeof(PRODUCTO), SEEK_CUR);
                fwrite(&p, sizeof(PRODUCTO), 1, arch);
                break;
            }
        }
    }
    fclose(arch);
}

void nuevos_productos() {
    FILE *old = fopen("com.dat", "rb");
    FILE *new_f = fopen("com_new.dat", "wb");
    PRODUCTO nuevo, actual;
    int insertado;

    printf("Registro de nuevos productos (Clave 0 para terminar):\n");
    while (scanf("%d", &nuevo.clave) && nuevo.clave != 0) {
        getchar();
        printf("Nombre: "); gets(nuevo.nombre);
        printf("Existencia: "); scanf("%d", &nuevo.existencia);
        printf("Precio: "); scanf("%f", &nuevo.precio);

        rewind(old);
        insertado = 0;
        while (fread(&actual, sizeof(PRODUCTO), 1, old)) {
            if (!insertado && nuevo.clave < actual.clave) {
                fwrite(&nuevo, sizeof(PRODUCTO), 1, new_f);
                insertado = 1;
            }
            fwrite(&actual, sizeof(PRODUCTO), 1, new_f);
        }
        if (!insertado) fwrite(&nuevo, sizeof(PRODUCTO), 1, new_f);

        fclose(old); fclose(new_f);
        remove("com.dat");
        rename("com_new.dat", "com.dat");
        old = fopen("com.dat", "rb");
        new_f = fopen("com_new.dat", "wb");
    }
    fclose(old); fclose(new_f);
}

void inventario() {
    FILE *arch = fopen("com.dat", "rb");
    PRODUCTO p;
    if (!arch) { printf("No hay datos.\n"); return; }
    printf("\n%-10s %-20s %-10s %-10s\n", "CLAVE", "NOMBRE", "EXIST.", "PRECIO");
    while (fread(&p, sizeof(PRODUCTO), 1, arch)) {
        printf("%-10d %-20s %-10d %-10.2f\n", p.clave, p.nombre, p.existencia, p.precio);
    }
    fclose(arch);
}
