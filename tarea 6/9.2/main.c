#include <stdio.h>

int cuenta(char);  /* Prototipo */

int main()
{
    int res;
    char car;

    printf("\nIngrese el caracter que se va a buscar en el archivo: ");
    scanf(" %c", &car);

    res = cuenta(car);

    if (res != -1)
    {
        printf("\n\nEl caracter %c se encuentra en el archivo %d veces", car, res);
    }
    else
    {
        printf("\nNo se pudo abrir el archivo");
    }

    return 0;
}

int cuenta(char car)
{
    int con = 0;
    char p;
    FILE *ar;

    ar = fopen("arc.txt", "r");

    if (ar != NULL)
    {
        while ((p = fgetc(ar)) != EOF)
        {
            if (p == car)
            {
                con++;
            }
        }

        fclose(ar);
        return con;
    }
    else
    {
        return -1;
    }
}
