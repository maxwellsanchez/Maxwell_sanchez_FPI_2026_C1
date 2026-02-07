#include <stdio.h>
#include <stdlib.h>
#define NUEVO 100
#define SALIR 0
#define SUMAR 1
#define DIVIDIR 2
#define MULTIPLICAR 3
#define RESTAR 4
// concepto de funcion
// concepto de puntero
float sumar(float num1, float num2);
int main()
{
    int menu = NUEVO;
    float num1 = 0.0;
    float num2 = 0.0;
    float result = 0.0;

    do
    {
            printf("\n0-Salir\n1-sumar\n2dividir\n3multiplicar\n4restar\n");
            scanf("%i",&menu);
            if(menu == SUMAR)
    {
        printf("\nEscriba el primer numero a sumar\n");
        scanf("%f",&num1);
        printf("\nEscriba el segundo numero a sumar\n");
        scanf("%f",&num2);
        result = sumar(num1,num2) ;
        printf("suma de %f y %f es:%f",num1,num2,result);
    }

    }while(menu !=SALIR) ;

}

float sumar(float num1,float num2)
{
    return num1 + num2;
}
