#include <stdio.h>
#include <string.h>

typedef struct {
    char calle_num[50];
    char cp[10];
    char colonia[50];
    char ciudad[50];
} DOMICILIO;

typedef struct {
    long long num_cuenta;
    char nombre[50];
    DOMICILIO dom;
    char telefono[15];
    float saldo;
} CLIENTE;

// prototipos
int buscar_cuenta(CLIENTE cli[], int n, long long cuenta);
void realizar_operaciones(CLIENTE cli[], int n);

int main() {
    int n, i;
    CLIENTE cli[100];

    printf("Cantidad de clientes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nCuenta: ");
        scanf("%lld", &cli[i].num_cuenta);
        printf("Nombre: ");
        fflush(stdin);
        gets(cli[i].nombre);
        printf("Calle y Num: ");
        gets(cli[i].dom.calle_num);
        printf("CP: ");
        gets(cli[i].dom.cp);
        printf("Colonia: ");
        gets(cli[i].dom.colonia);
        printf("Ciudad: ");
        gets(cli[i].dom.ciudad);
        printf("Tel: ");
        gets(cli[i].telefono);
        printf("Saldo: ");
        scanf("%f", &cli[i].saldo);
    }

    realizar_operaciones(cli, n);

    return 0;
}

int buscar_cuenta(CLIENTE cli[], int n, long long cuenta) {
    int izq = 0, der = n - 1, centro;
    while (izq <= der) {
        centro = (izq + der) / 2;
        if (cli[centro].num_cuenta == cuenta) return centro;
        if (cuenta < cli[centro].num_cuenta) der = centro - 1;
        else izq = centro + 1;
    }
    return -1;
}

void realizar_operaciones(CLIENTE cli[], int n) {
    long long cuenta;
    int pos, op;
    float monto;

    do {
        printf("\nCuenta (0 para salir): ");
        scanf("%lld", &cuenta);
        if (cuenta == 0) break;

        pos = buscar_cuenta(cli, n, cuenta);

        if (pos != -1) {
            printf("1.Deposito, 2.Retiro: ");
            scanf("%d", &op);
            printf("Monto: ");
            scanf("%f", &monto);

            if (op == 1) {
                cli[pos].saldo += monto;
                printf("Nuevo saldo: %.2f\n", cli[pos].saldo);
            } else if (op == 2) {
                if (cli[pos].saldo >= monto) {
                    cli[pos].saldo -= monto;
                    printf("Nuevo saldo: %.2f\n", cli[pos].saldo);
                } else {
                    printf("Saldo insuficiente.\n");
                }
            }
        } else {
            printf("No existe.\n");
        }
    } while (cuenta != 0);
}
