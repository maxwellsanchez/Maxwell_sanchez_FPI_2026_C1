#include <stdio.h>

int main() {
    int VOTO;
    int C1=0, C2=0, C3=0, C4=0, C5=0;
    float TOTAL = 0;

    printf("Ingrese los votos (1 a 5). Use 0 para terminar:\n");
    scanf("%d", &VOTO);

    while (VOTO != 0) {
        if (VOTO == 1) C1++;
        else if (VOTO == 2) C2++;
        else if (VOTO == 3) C3++;
        else if (VOTO == 4) C4++;
        else if (VOTO == 5) C5++;

        if (VOTO >= 1 && VOTO <= 5) {
            TOTAL++;
        }

        scanf("%d", &VOTO);
    }

    if (TOTAL > 0) {
        printf("\nResultados de la Eleccion:");
        printf("\nCandidato 1: %d votos - %.2f%%", C1, (C1/TOTAL)*100);
        printf("\nCandidato 2: %d votos - %.2f%%", C2, (C2/TOTAL)*100);
        printf("\nCandidato 3: %d votos - %.2f%%", C3, (C3/TOTAL)*100);
        printf("\nCandidato 4: %d votos - %.2f%%", C4, (C4/TOTAL)*100);
        printf("\nCandidato 5: %d votos - %.2f%%", C5, (C5/TOTAL)*100);
    } else {
        printf("\nNo se registraron votos.");
    }

    return 0;
}
