#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* 1. DOMICILIO debe ir primero */
typedef struct {
    char calle[50];
    int numero;
    char colonia[50];
    char cp[10];
    char ciudad[50];
    char telefono[15];
} DOMICILIO;

/* 2. Luego PACIENTE que usa a DOMICILIO */
typedef struct {
    int clave;
    char nombre[100];
    int edad;
    char sexo;
    int condicion;
    DOMICILIO dom; /* Esto daria error si DOMICILIO no estuviera arriba */
} PACIENTE;

int main() {
    FILE *archivo;
    PACIENTE p;
    int total = 0, h = 0, m = 0;
    int cond[6] = {0}, edades[11] = {0};

    archivo = fopen("pacientes.dat", "rb");

    if (archivo == NULL) {
        printf("Error: No se pudo abrir 'pacientes.dat'.\n");
        printf("Asegurate de que el archivo exista en la misma carpeta que el .exe\n");
        return 1;
    }

    /* fread devuelve el numero de elementos leidos.
       Mientras sea 1, el bucle continua. */
    while (fread(&p, sizeof(PACIENTE), 1, archivo) == 1) {
        total++;

        /* Conteo Sexo */
        if (toupper(p.sexo) == 'M') h++;
        else if (toupper(p.sexo) == 'F') m++;

        /* Conteo Condicion */
        if (p.condicion >= 1 && p.condicion <= 5) cond[p.condicion]++;

        /* Conteo Edades */
        if (p.edad >= 100) edades[10]++;
        else if (p.edad >= 0) edades[p.edad / 10]++;
    }

    fclose(archivo);

    if (total > 0) {
        printf("--- RESULTADOS ---\n");
        printf("Total: %d\n", total);
        printf("Hombres: %.1f%% - Mujeres: %.1f%%\n", (float)h/total*100, (float)m/total*100);

        printf("\nCondiciones:\n");
        for(int i=1; i<=5; i++) printf("Cat %d: %d\n", i, cond[i]);
    } else {
        printf("El archivo esta vacio o no tiene el formato correcto.\n");
    }

    return 0;
}
