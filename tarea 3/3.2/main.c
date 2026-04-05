#include <stdio.h>

int main() {

    int I = 2;
    int SSE = 0;
    int CAM = 1;


    printf("Terminos de la serie:\n");


    while (I <= 2500) {
        printf("%d ", I);
        SSE = SSE + I;

        if (CAM == 1) {
            I = I + 5;
            CAM = 0;
        } else {
            I = I + 3;
            CAM = 1;
        }
    }

    printf("\n\nLa suma de todos los terminos es: %d\n", SSE);

    return 0;
}
