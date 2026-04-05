#include <stdio.h>
#include <string.h>

// Definicion de estructura
typedef struct {
    int id;
    char nombre[50];
    float ventas[12];
    float total_anual;
    float salario;
    char banco[30];
    char cuenta[20];
    int tipo_cuenta; // 1: Cheques, 2: Ahorros
} Empleado;

int main() {
    int n, i, j;

    printf("Cantidad de empleados a ingresar: ");
    scanf("%d", &n);

    Empleado emp[n];

    // Entrada de datos
    for (i = 0; i < n; i++) {
        printf("\n--- Datos del empleado %d ---\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Nombre: ");
        fflush(stdin);
        scanf(" %[^\n]", emp[i].nombre);
        printf("Salario base: ");
        scanf("%f", &emp[i].salario);

        emp[i].total_anual = 0;
        for (j = 0; j < 12; j++) {
            printf("Ventas mes %d: ", j + 1);
            scanf("%f", &emp[i].ventas[j]);
            // a) Acumular ventas totales
            emp[i].total_anual += emp[i].ventas[j];
        }

        printf("Banco: ");
        scanf(" %[^\n]", emp[i].banco);
        printf("Numero de cuenta: ");
        scanf("%s", emp[i].cuenta);
        printf("Tipo de cuenta (1: Cheques, 2: Otra): ");
        scanf("%d", &emp[i].tipo_cuenta);

        //  Incremento del 5% si supera 1,500,000
        if (emp[i].total_anual > 1500000) {
            emp[i].salario *= 1.05;
        }
    }

    //  Listado de ventas menores a 300,000
    printf("\n--- Empleados con ventas menores a $300,000 ---\n");
    for (i = 0; i < n; i++) {
        if (emp[i].total_anual < 300000) {
            printf("ID: %d | Nombre: %s | Ventas Totales: $%.2f\n",
                   emp[i].id, emp[i].nombre, emp[i].total_anual);
        }
    }

    //  Listado de depositos en cuenta de cheques
    printf("\n--- Empleados con deposito en cuenta de cheques ---\n");
    for (i = 0; i < n; i++) {
        if (emp[i].tipo_cuenta == 1) {
            printf("ID: %d | Banco: %s | Cuenta: %s\n",
                   emp[i].id, emp[i].banco, emp[i].cuenta);
        }
    }

    return 0;
}
