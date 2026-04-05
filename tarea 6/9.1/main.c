#include <stdio.h>

int main()
{
    int p1;
    FILE *ar;

    ar = fopen("libro.txt", "a");

    if (ar != NULL)
    {
        printf("Ingrese texto (Enter para terminar):\n");

        while ((p1 = getchar()) != '\n' && p1 != EOF)
        {
            fputc(p1, ar);
        }


        fputc('\n', ar);

        fclose(ar);
        printf("Texto guardado con exito.\n");
    }
    else
    {

        perror("Error al intentar abrir el archivo");
    }

    return 0;
}
