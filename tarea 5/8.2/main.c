#include <stdio.h>
#include <string.h>

/* Estructura para las materias */
struct MATERIA {
    char nombre_mat[30];
    float promedio;
};

/* Estructura principal del alumno */
struct ALUMNO {
    int matricula;
    char nombre[50];
    struct MATERIA materias[5]; // Se asumen 5 materias por alumno
};

void main() {
    struct ALUMNO ALU[50];
    int N, i, j;
    float sum_alumno, sum_materia4 = 0;

    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &N);

    /* Lectura de datos */
    for (i = 0; i < N; i++) {
        printf("\nMatricula alumno %d: ", i + 1);
        scanf("%d", &ALU[i].matricula);
        fflush(stdin);
        printf("Nombre y apellido: ");
        gets(ALU[i].nombre);

        for (j = 0; j < 5; j++) {
            printf("Materia %d: ", j + 1);
            fflush(stdin);
            gets(ALU[i].materias[j].nombre_mat);
            printf("Promedio: ");
            scanf("%f", &ALU[i].materias[j].promedio);
        }
    }

    /* Inciso A: Matricula y promedio general de cada alumno */
    printf("\n--- Reporte de Promedios Generales ---");
    for (i = 0; i < N; i++) {
        sum_alumno = 0;
        for (j = 0; j < 5; j++) {
            sum_alumno += ALU[i].materias[j].promedio;
        }
        printf("\nMatricula: %d | Promedio General: %.2f", ALU[i].matricula, sum_alumno / 5);
    }

    /* Inciso B: Alumnos con mas de 9 en la tercera materia (indice 2) */
    printf("\n\n--- Alumnos con mas de 9 en la materia 3 ---");
    for (i = 0; i < N; i++) {
        if (ALU[i].materias[2].promedio > 9) {
            printf("\nMatricula: %d", ALU[i].matricula);
        }
    }

    /* Inciso C: Promedio general de la materia 4 (indice 3) */
    for (i = 0; i < N; i++) {
        sum_materia4 += ALU[i].materias[3].promedio;
    }
    printf("\n\nPromedio general de la materia 4: %.2f\n", sum_materia4 / N);
}
