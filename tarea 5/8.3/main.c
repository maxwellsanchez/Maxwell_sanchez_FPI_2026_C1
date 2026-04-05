#include <stdio.h>
#include <string.h>

struct DOMICILIO {
    char calle[30];
    int numero;
    char colonia[30];
    char cp[10];
    char ciudad[30];
    char telefono[15];
};

struct PACIENTE {
    char nombre[50];
    int edad;
    char sexo;
    int condicion;
    struct DOMICILIO dom;
};

void main() {
    struct PACIENTE HOSPITAL[100];
    int N, i;
    int cont_h = 0, cont_m = 0;
    int cat[6] = {0, 0, 0, 0, 0, 0};

    printf("--- REGISTRO HOSPITALARIO ---\n");
    printf("Ingrese la cantidad de pacientes a registrar: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        printf("\n>>> DATOS DEL PACIENTE %d <<<\n", i + 1);

        // Limpiar buffer antes de leer cadenas despues de un entero
        fflush(stdin);

        printf("Nombre y Apellido: ");
        gets(HOSPITAL[i].nombre);

        printf("Edad: ");
        scanf("%d", &HOSPITAL[i].edad);

        printf("Sexo (H/M): ");
        scanf(" %c", &HOSPITAL[i].sexo);

        printf("Condicion de ingreso (1-5): ");
        scanf("%d", &HOSPITAL[i].condicion);

        fflush(stdin);
        printf("Calle: ");
        gets(HOSPITAL[i].dom.calle);

        printf("Numero de casa: ");
        scanf("%d", &HOSPITAL[i].dom.numero);

        fflush(stdin);
        printf("Colonia: ");
        gets(HOSPITAL[i].dom.colonia);

        printf("Codigo Postal: ");
        gets(HOSPITAL[i].dom.cp);

        printf("Ciudad: ");
        gets(HOSPITAL[i].dom.ciudad);

        printf("Telefono: ");
        gets(HOSPITAL[i].dom.telefono);

        // Procesamiento de datos para los reportes
        if (HOSPITAL[i].sexo == 'H' || HOSPITAL[i].sexo == 'h') cont_h++;
        if (HOSPITAL[i].sexo == 'M' || HOSPITAL[i].sexo == 'm') cont_m++;

        if (HOSPITAL[i].condicion >= 1 && HOSPITAL[i].condicion <= 5) {
            cat[HOSPITAL[i].condicion]++;
        }
    }

    // Reporte A: Porcentajes
    printf("\n========================================");
    printf("\nREPORTES GENERALES");
    printf("\n========================================");

    if (N > 0) {
        printf("\n\na) PORCENTAJE POR GENERO:");
        printf("\n   Hombres: %.2f%%", (float)cont_h * 100 / N);
        printf("\n   Mujeres: %.2f%%", (float)cont_m * 100 / N);
    }

    // Reporte B: Categorias
    printf("\n\nb) PACIENTES POR NIVEL DE CONDICION:");
    for (i = 1; i <= 5; i++) {
        printf("\n   Nivel %d: %d", i, cat[i]);
    }

    // Reporte C: Casos de Gravedad Maxima
    printf("\n\nc) PACIENTES EN ESTADO CRITICO (NIVEL 5):");
    int hay_graves = 0;
    for (i = 0; i < N; i++) {
        if (HOSPITAL[i].condicion == 5) {
            printf("\n   -> Nombre: %s | Tel: %s", HOSPITAL[i].nombre, HOSPITAL[i].dom.telefono);
            hay_graves = 1;
        }
    }
    if (!hay_graves) printf("\n   No se registraron pacientes en nivel 5.");

    printf("\n\nFin del programa.\n");
}
