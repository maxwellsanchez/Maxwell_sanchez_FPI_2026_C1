#include <stdio.h>

int main() {
    long PRI = 0, SEG = 1, SIG;
    int I;

    printf("Serie de Fibonacci (50 terminos):\n");
    printf("%ld, %ld, ", PRI, SEG);

    for (I = 3; I <= 50; I++) {
        SIG = PRI + SEG;
        printf("%ld", SIG);

        if (I < 50) printf(", ");

        PRI = SEG;
        SEG = SIG;
    }

    return 0;
}
