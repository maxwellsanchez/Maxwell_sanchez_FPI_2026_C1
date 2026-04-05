#include <stdio.h>
#include <string.h>

struct UBICACION {
    char zona[30];
    char calle[30];
    char colonia[30];
};

struct PROPIEDAD {
    char clave[15];
    float sup_cubierta;
    float sup_terreno;
    char caracteristicas[100];
    struct UBICACION ubi;
    float precio;
    char disponibilidad; // 'V' o 'R'
};

void main() {
    struct PROPIEDAD PROPIE[100];
    int N, i;
    char zona_busq[30];
    float p_min, p_max;

    printf("--- SISTEMA DE BIENES RAICES ---\n");
    printf("Ingrese cantidad de propiedades: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        printf("\n>>> DATOS DE LA PROPIEDAD %d <<<\n", i + 1);

        fflush(stdin);
        printf("Clave de propiedad: ");
        gets(PROPIE[i].clave);

        printf("Superficie cubierta (m2): ");
        scanf("%f", &PROPIE[i].sup_cubierta);

        printf("Superficie del terreno (m2): ");
        scanf("%f", &PROPIE[i].sup_terreno);

        fflush(stdin);
        printf("Caracteristicas: ");
        gets(PROPIE[i].caracteristicas);

        printf("Zona: ");
        gets(PROPIE[i].ubi.zona);

        printf("Calle: ");
        gets(PROPIE[i].ubi.calle);

        printf("Colonia: ");
        gets(PROPIE[i].ubi.colonia);

        printf("Precio (Soles): ");
        scanf("%f", &PROPIE[i].precio);

        printf("Disponibilidad (V = Venta / R = Renta): ");
        scanf(" %c", &PROPIE[i].disponibilidad);
    }

    /* a) Listado Venta Miraflores 450k-650k */
    printf("\n========================================");
    printf("\nPROPIEDADES DISPONIBLES: VENTA MIRAFLORES");
    printf("\n========================================");
    for (i = 0; i < N; i++) {
        if ((PROPIE[i].disponibilidad == 'V' || PROPIE[i].disponibilidad == 'v') &&
            strcmp(PROPIE[i].ubi.zona, "Miraflores") == 0 &&
            PROPIE[i].precio >= 450000 && PROPIE[i].precio <= 650000) {

            printf("\nClave: %s | Precio: %.2f", PROPIE[i].clave, PROPIE[i].precio);
        }
    }

    /* b) Busqueda personalizada para Renta */
    printf("\n\n--- BUSQUEDA PERSONALIZADA DE RENTA ---");
    fflush(stdin);
    printf("\nIngrese zona a buscar: ");
    gets(zona_busq);
    printf("Ingrese precio minimo: ");
    scanf("%f", &p_min);
    printf("Ingrese precio maximo: ");
    scanf("%f", &p_max);

    printf("\nResultados encontrados:");
    for (i = 0; i < N; i++) {
        if ((PROPIE[i].disponibilidad == 'R' || PROPIE[i].disponibilidad == 'r') &&
            strcmp(PROPIE[i].ubi.zona, zona_busq) == 0 &&
            PROPIE[i].precio >= p_min && PROPIE[i].precio <= p_max) {

            printf("\n------------------------------------");
            printf("\nClave: %s", PROPIE[i].clave);
            printf("\nSuperficies: Cubierta %.2f | Total %.2f", PROPIE[i].sup_cubierta, PROPIE[i].sup_terreno);
            printf("\nCaracteristicas: %s", PROPIE[i].caracteristicas);
            printf("\nUbicacion: %s, %s", PROPIE[i].ubi.calle, PROPIE[i].ubi.colonia);
            printf("\nPrecio: S/ %.2f", PROPIE[i].precio);
        }
    }
    printf("\n\nFin de la consulta.\n");
}
