#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    float c1, c2, c3;
} ALUMNO;

int main() {
    FILE *arch_ent, *arch_sal;
    ALUMNO alumnos[500]; // ajuste segun cantidad esperada
    ALUMNO aux;
    int n = 0, i, j;

    arch_ent = fopen("arc.dat", "r");
    if (arch_ent == NULL) {
        perror("Error al abrir arc.dat");
        return 1;
    }

    // leer datos a memoria
    while (fscanf(arch_ent, "%d %f %f %f", &alumnos[n].matricula,
                  &alumnos[n].c1, &alumnos[n].c2, &alumnos[n].c3) != EOF) {
        n++;
    }
    fclose(arch_ent);

    // ordenamiento por metodo de burbuja (ascendente por matricula)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (alumnos[i].matricula > alumnos[j].matricula) {
                aux = alumnos[i];
                alumnos[i] = alumnos[j];
                alumnos[j] = aux;
            }
        }
    }

    arch_sal = fopen("arc1.dat", "w");
    if (arch_sal == NULL) {
        perror("Error al crear arc1.dat");
        return 1;
    }

    // escribir datos ordenados
    for (i = 0; i < n; i++) {
        fprintf(arch_sal, "%d\t%.1f\t%.1f\t%.1f\n", alumnos[i].matricula,
                alumnos[i].c1, alumnos[i].c2, alumnos[i].c3);
    }
    fclose(arch_sal);

    printf("Archivo arc1.dat generado y ordenado exitosamente.\n");

    return 0;
}
