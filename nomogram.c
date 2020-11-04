// copyright 312CA Dalimon Iarina
#include <stdio.h>

int main() {
    int t, n, m, i, j, var, cif, l[100][100], c[100][100], g[100][100];
    int suma_1, suma_2, suma_3, suma_4;
    scanf("%d", &t);
    while (t > 0) {
        var = 1;
        scanf("%d", &n);
        scanf("%d", &m);
        for (i = 0; i < n; i++) { // formare matrice restrictii linii
            scanf("%d", &l[i][0]);
            cif = l[i][0];
            for (j = 1; j <= cif; j++) {
                scanf("%d", &l[i][j]);
            }
            cif++;
            for (j = cif; j < m; j++) {
                l[i][j] = 0;
            }
        }
        for (i = 0; i < m; i++) { // formare matrice restrictii coloane
            scanf("%d", &c[i][0]);
            cif = c[i][0];
            for (j = 1; j <= cif; j++) {
                scanf("%d", &c[i][j]);
            }
            cif++;
            for (j = cif; j < n; j++) {
                c[i][j] = 0;
            }
        }
        for (i = 0; i < n; i++) { // citire grid
            for (j = 0; j < m; j++) {
                scanf("%d", &g[i][j]);
            }
        }
        for (i = 0; i < n; i++) {
            suma_1 = 0;
            suma_2 = 0;
            for (j = 0; j < m; j++) {
                suma_1 += g[i][j]; // suma pe linii grid
                if (j > 0) {
                    suma_2 += l[i][j]; // suma pe liniile matr reguli linii
                }
            }
            if (suma_1 != suma_2) {
                var = 0;
            }
        }
        for (i = 0; i < m; i++) {
            suma_3 = 0;
            suma_4 = 0;
            for (j = 0; j < n; j++) {
                suma_3 += g[j][i]; // suma pe coloane grid
                suma_4 += c[i][j]; // suma pe liniile matr reguli coloane
            }
            suma_4 -= c[i][0];
            if (suma_3 != suma_4) {
                var = 0;
            }
        }
        if (var == 1) {
            printf("Corect\n");
        } else {
            printf("Eroare\n");
        }
        t--;
    }
    return 0;
}
