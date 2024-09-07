#include <stdio.h>

int busquedaTernaria(int [], int, int, int);

void main() {
    int a[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 13;

    int indice = busquedaTernaria(a, 0, n - 1, x);

    if (indice != -1) {
        printf("El elemento %d se encuentra en la posicion %d del arreglo.\n", x, indice);
    } else {
        printf("El elemento %d no se encuentra en el arreglo.\n", x);
    }

}

int busquedaTernaria(int a[], int ini, int fin, int x) {
    if (ini <= fin) {
        int tercio1 = ini + (fin - ini) / 3;
        int tercio2 = fin - (fin - ini) / 3;

        if (a[tercio1] == x) {
            return tercio1;
        }

        if (a[tercio2] == x) {
            return tercio2;
        }

        if (x < a[tercio1]) {
            return busquedaTernaria(a, ini, tercio1 - 1, x);
        } else if (x > a[tercio2]) {
            return busquedaTernaria(a, tercio2 + 1, fin, x);
        } else {
            return busquedaTernaria(a, tercio1 + 1, tercio2 - 1, x);
        }
    }
    return -1;
}