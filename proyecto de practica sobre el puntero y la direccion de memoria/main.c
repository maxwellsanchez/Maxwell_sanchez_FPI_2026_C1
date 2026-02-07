#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5;
    int *p;

    p = &a;
    printf("\nvalor de p[%p]",p);
     printf("\nvalor de a[%i]",*p);
    return 0;
}
