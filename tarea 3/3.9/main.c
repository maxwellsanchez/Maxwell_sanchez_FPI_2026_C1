#include <stdio.h>

int main() {
    int MAT;
    float CAL, SUM_CAL, PRO;

    int MAT_MEJOR, MAT_PEOR;
    float PRO_MEJOR = -1;
    float PRO_PEOR = 11;

    printf("Ingrese matricula (0 para terminar): ");
    scanf("%d", &MAT);

    while (MAT != 0) {
        SUM_CAL = 0;

        for (int j = 1; j <= 5; j++) {
            printf("Calificacion %d: ", j);
            scanf("%f", &CAL);
            SUM_CAL += CAL;
        }

        PRO = SUM_CAL / 5;
        printf("Alumno %d - Promedio: %.2f\n\n", MAT, PRO);

        if (PRO > PRO_MEJOR) {
            PRO_MEJOR = PRO;
            MAT_MEJOR = MAT;
        }

        if (PRO < PRO_PEOR) {
            PRO_PEOR = PRO;
            MAT_PEOR = MAT;
        }

        printf("Siguiente matricula (0 para terminar): ");
        scanf("%d", &MAT);
    }

    if (PRO_MEJOR != -1) {
        printf("\n--- RESULTADOS FINALES ---");
        printf("\nMEJOR ALUMNO: Matricula %d con promedio %.2f", MAT_MEJOR, PRO_MEJOR);
        printf("\nPEOR ALUMNO:  Matricula %d con promedio %.2f\n", MAT_PEOR, PRO_PEOR);
    }

    return 0;
}
