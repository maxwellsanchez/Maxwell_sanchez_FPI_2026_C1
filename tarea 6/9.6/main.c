#include <stdio.h>
#include <string.h>

void cambia(FILE *, FILE *);  /* Prototipo */

int main()
{
    FILE *ar;
    FILE *ap;

    ar = fopen("arc.txt", "r");
    ap = fopen("arc1.txt", "w");

    if ((ar != NULL) && (ap != NULL))
    {
        cambia(ar, ap);
        fclose(ar);
        fclose(ap);
    }
    else
    {
        printf("No se pueden abrir los archivos");
    }

    return 0;
}

void cambia(FILE *ap1, FILE *ap2)
{
    char cad[100];
    char *cad2;

    while (fgets(cad, 100, ap1) != NULL)
    {
        cad2 = strstr(cad, "mexico");

        while (cad2 != NULL)
        {
            cad2[0] = 'M';
            cad2 = strstr(cad2 + 1, "mexico");
        }

        fputs(cad, ap2);
    }
}
