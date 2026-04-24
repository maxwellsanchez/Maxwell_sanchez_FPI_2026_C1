#include <stdio.h>
#include <string.h>

typedef struct {
    int num_empleado;
    char nombre[100];
    char departamento[50];
    char puesto[50];
    char grado[50];
    char nacionalidad[50];
    float salario[12];
} PROFESOR;

void calcular_resultados(PROFESOR emple[], int n) {
    float max_ganancia = -1, total_universidad = 0, total_extranjeros = 0;
    int indice_max = 0;

    float egresos_depto[4] = {0}; // 0:Economia, 1:Derecho, 2:Computacion, 3:Administracion
    char *deptos[] = {"Economia", "Derecho", "Computacion", "Administracion"};

    for (int i = 0; i < n; i++) {
        float total_profesor = 0;
        for (int j = 0; j < 12; j++) {
            total_profesor += emple[i].salario[j];
        }

        // a) Profesor que mas gano
        if (total_profesor > max_ganancia) {
            max_ganancia = total_profesor;
            indice_max = i;
        }

        // b) Acumulados para extranjeros y total
        total_universidad += total_profesor;
        if (strcasecmp(emple[i].nacionalidad, "Colombia") != 0 &&
            strcasecmp(emple[i].nacionalidad, "Colombiana") != 0) {
            total_extranjeros += total_profesor;
        }

        // c) Egresos por departamento
        for (int k = 0; k < 4; k++) {
            if (strcasecmp(emple[i].departamento, deptos[k]) == 0) {
                egresos_depto[k] += total_profesor;
                break;
            }
        }
    }

    // Resultados A
    printf("\n--- Profesor con mayor ingreso ---");
    printf("\nNombre: %s", emple[indice_max].nombre);
    printf("\nDepartamento: %s", emple[indice_max].departamento);
    printf("\nNacionalidad: %s", emple[indice_max].nacionalidad);
    printf("\nIngreso Total: %.2f\n", max_ganancia);

    // Resultados B
    printf("\n--- Profesores Extranjeros ---");
    printf("\nMonto total pagado: %.2f", total_extranjeros);
    if (total_universidad > 0)
        printf("\nPorcentaje del total: %.2f%%\n", (total_extranjeros / total_universidad) * 100);

    // Resultados C
    float max_egreso_depto = -1;
    int indice_depto_max = 0;
    for (int k = 0; k < 4; k++) {
        if (egresos_depto[k] > max_egreso_depto) {
            max_egreso_depto = egresos_depto[k];
            indice_depto_max = k;
        }
    }
    printf("\n--- Departamento con mayor egreso ---");
    printf("\nDepartamento: %s (Total: %.2f)\n", deptos[indice_depto_max], max_egreso_depto);
}

int main() {
    int n;
    PROFESOR emple[200];

    printf("Ingrese cantidad de profesores (N): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nProfesor %d", i + 1);
        printf("\nNum Empleado: ");
        scanf("%d", &emple[i].num_empleado);
        getchar();
        printf("Nombre y Apellido: ");
        gets(emple[i].nombre);
        printf("Departamento (Economia/Derecho/Computacion/Administracion): ");
        gets(emple[i].departamento);
        printf("Nacionalidad: ");
        gets(emple[i].nacionalidad);

        printf("Ingresar los 12 salarios mensuales:\n");
        for (int j = 0; j < 12; j++) {
            scanf("%f", &emple[i].salario[j]);
        }
        getchar();
    }

    if (n > 0) calcular_resultados(emple, n);

    return 0;
}

