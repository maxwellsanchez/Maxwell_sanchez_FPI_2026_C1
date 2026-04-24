#include <stdio.h>
#include <string.h>

typedef struct {
    int matricula;
    char nombre[50];
    int carrera;
    float promedio;
} ALUMNO;

int main() {
    FILE *archivo_lectura, *archivo_escritura;
    ALUMNO actual, anterior;
    int primero = 1;

    archivo_lectura = fopen("ad5.dat", "rb");
    if (archivo_lectura == NULL) {
        perror("Error al abrir ad5.dat");
        return 1;
    }

    archivo_escritura = fopen("ad5_unico.dat", "wb");
    if (archivo_escritura == NULL) {
        perror("Error al crear archivo de salida");
        fclose(archivo_lectura);
        return 1;
    }

    // lectura secuencial aprovechando que estan ordenados
    while (fread(&actual, sizeof(ALUMNO), 1, archivo_lectura)) {
        if (primero) {
            fwrite(&actual, sizeof(ALUMNO), 1, archivo_escritura);
            anterior = actual;
            primero = 0;
        } else {
            // solo escribe si la matricula es diferente a la anterior
            if (actual.matricula != anterior.matricula) {
                fwrite(&actual, sizeof(ALUMNO), 1, archivo_escritura);
                anterior = actual;
            }
        }
    }

    fclose(archivo_lectura);
    fclose(archivo_escritura);

    printf("Proceso finalizado. Registros duplicados eliminados.\n");

    return 0;
}
