#include <stdio.h>
#include <string.h>

typedef struct {
    char calle_num[50];
    char colonia[50];
    char cp[10];
    char ciudad[50];
} DOMICILIO;

typedef struct {
    int num_empleado;
    char nombre[100];
    char departamento[50];
    DOMICILIO dom;
    char telefono[15];
    float salario;
} EMPLEADO;

int buscar(EMPLEADO emple[], int n, int num);
void altas(EMPLEADO emple[], int *n);
void bajas(EMPLEADO emple[], int *n);
void listado(EMPLEADO emple[], int n);

int main() {
    EMPLEADO emple[100];
    int n = 0;
    int opcion;

    do {
        printf("\n--- SISTEMA RRHH SANTIAGO ---\n");
        printf("1. Alta de empleado\n");
        printf("2. Baja de empleado\n");
        printf("3. Listado por departamento\n");
        printf("4. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: altas(emple, &n); break;
            case 2: bajas(emple, &n); break;
            case 3: listado(emple, n); break;
        }
    } while (opcion != 4);

    return 0;
}

int buscar(EMPLEADO emple[], int n, int num) {
    int izq = 0, der = n - 1, centro;
    while (izq <= der) {
        centro = (izq + der) / 2;
        if (emple[centro].num_empleado == num) return centro;
        if (num < emple[centro].num_empleado) der = centro - 1;
        else izq = centro + 1;
    }
    return -1;
}

void altas(EMPLEADO emple[], int *n) {
    int num, pos, i;
    if (*n >= 100) {
        printf("Capacidad maxima alcanzada.\n");
        return;
    }

    printf("Numero de empleado: ");
    scanf("%d", &num);
    pos = buscar(emple, *n, num);

    if (pos != -1) {
        printf("El empleado ya existe.\n");
    } else {
        // Encontrar posicion para mantener orden
        i = *n - 1;
        while (i >= 0 && emple[i].num_empleado > num) {
            emple[i + 1] = emple[i];
            i--;
        }

        emple[i + 1].num_empleado = num;
        getchar();
        printf("Nombre y Apellido: ");
        gets(emple[i + 1].nombre);
        printf("Departamento: ");
        gets(emple[i + 1].departamento);
        printf("Calle y Num: ");
        gets(emple[i + 1].dom.calle_num);
        printf("Colonia: ");
        gets(emple[i + 1].dom.colonia);
        printf("CP: ");
        gets(emple[i + 1].dom.cp);
        printf("Ciudad: ");
        gets(emple[i + 1].dom.ciudad);
        printf("Telefono: ");
        gets(emple[i + 1].telefono);
        printf("Salario mensual: ");
        scanf("%f", &emple[i + 1].salario);

        (*n)++;
        printf("Alta exitosa.\n");
    }
}

void bajas(EMPLEADO emple[], int *n) {
    int num, pos, i;
    printf("Numero de empleado a dar de baja: ");
    scanf("%d", &num);
    pos = buscar(emple, *n, num);

    if (pos == -1) {
        printf("Empleado no encontrado.\n");
    } else {
        for (i = pos; i < *n - 1; i++) {
            emple[i] = emple[i + 1];
        }
        (*n)--;
        printf("Baja realizada.\n");
    }
}

void listado(EMPLEADO emple[], int n) {
    char depto[50];
    int hallado = 0;
    getchar();
    printf("Departamento a listar: ");
    gets(depto);

    printf("\n%-10s | %-20s | %-10s\n", "ID", "NOMBRE", "SALARIO");
    for (int i = 0; i < n; i++) {
        if (strcmp(emple[i].departamento, depto) == 0) {
            printf("%-10d | %-20s | %-10.2f\n",
                   emple[i].num_empleado, emple[i].nombre, emple[i].salario);
            hallado = 1;
        }
    }
    if (!hallado) printf("No hay empleados en ese departamento.\n");
}
