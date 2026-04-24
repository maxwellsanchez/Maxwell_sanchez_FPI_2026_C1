#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int pj, pg, pe, pp, gf, gc, dg, pts;
} EQUIPO;

// inicializa nombres para que coincidan con la busqueda
void inicializar_equipos(EQUIPO f[]) {
    char *nombres[] = {"America", "Puebla", "CruzAzul", "Veracruz", "Necaxa",
                       "Monterrey", "Chivas", "Pumas", "Toluca", "Tigres",
                       "Santos", "Leon", "Atlas", "Xolos", "Pachuca",
                       "Juarez", "Mazatlan", "Queretaro", "SanLuis", "Necaxa"};
    for(int i = 0; i < 20; i++) {
        strcpy(f[i].nombre, nombres[i]);
        f[i].pj = f[i].pg = f[i].pe = f[i].pp = 0;
        f[i].gf = f[i].gc = f[i].dg = f[i].pts = 0;
    }
}

void ordenar_tabla(EQUIPO f[], int n) {
    int i, j;
    EQUIPO aux;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (f[i].pts < f[j].pts) {
                aux = f[i]; f[i] = f[j]; f[j] = aux;
            }
        }
    }
}

int buscar_indice(EQUIPO f[], int n, char nom[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(f[i].nombre, nom) == 0) return i;
    }
    return -1;
}

int main() {
    EQUIPO futbol[20];
    int n = 20;
    char eq1[50], eq2[50], guion[2];
    int g1, g2;

    inicializar_equipos(futbol);

    printf("Formato: EquipoLocal Goles - EquipoVisita Goles (0 para terminar)\n");

    while (1) {
        scanf("%s", eq1);
        if (strcmp(eq1, "0") == 0) break;

        // lectura: Equipo1 Goles - Equipo2 Goles
        scanf("%d %s %s %d", &g1, guion, eq2, &g2);

        int i1 = buscar_indice(futbol, n, eq1);
        int i2 = buscar_indice(futbol, n, eq2);

        if (i1 != -1 && i2 != -1) {
            futbol[i1].pj++; futbol[i2].pj++;
            futbol[i1].gf += g1; futbol[i1].gc += g2;
            futbol[i2].gf += g2; futbol[i2].gc += g1;
            futbol[i1].dg = futbol[i1].gf - futbol[i1].gc;
            futbol[i2].dg = futbol[i2].gf - futbol[i2].gc;

            if (g1 > g2) {
                futbol[i1].pg++; futbol[i1].pts += 3;
                futbol[i2].pp++;
            } else if (g2 > g1) {
                futbol[i2].pg++; futbol[i2].pts += 3;
                futbol[i1].pp++;
            } else {
                futbol[i1].pe++; futbol[i1].pts += 1;
                futbol[i2].pe++; futbol[i2].pts += 1;
            }
        } else {
            printf("Error: Uno de los equipos no esta en la base de datos.\n");
        }
    }

    ordenar_tabla(futbol, n);

    printf("\n%-15s | PJ | GF | GC | DG | PTS\n", "EQUIPO");
    for (int i = 0; i < n; i++) {
        if(futbol[i].pj >= 0) { // muestra todos para ver la tabla
            printf("%-15s | %2d | %2d | %2d | %2d | %2d\n",
               futbol[i].nombre, futbol[i].pj, futbol[i].gf,
               futbol[i].gc, futbol[i].dg, futbol[i].pts);
        }
    }

    return 0;
}
