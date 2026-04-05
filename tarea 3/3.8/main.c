#include <stdio.h>
#include <math.h> // Necesaria para fabs() y M_PI

int main() {
    double PI_SERIE = 0;
    double DEN = 1.0;
    int BANDERA = 1;
    int CONTADOR = 0;


    double PI_REAL = 3.141592653589;


    while (fabs(PI_REAL - PI_SERIE) >= 0.0005) {
        if (BANDERA == 1) {
            PI_SERIE = PI_SERIE + (4.0 / DEN);
            BANDERA = 0;
        } else {
            PI_SERIE = PI_SERIE - (4.0 / DEN);
            BANDERA = 1;
        }

        DEN = DEN + 2;
        CONTADOR++;
    }

    printf("Valor aproximado de PI: %f\n", PI_SERIE);
    printf("Terminos necesarios: %d\n", CONTADOR);

    return 0;
}
