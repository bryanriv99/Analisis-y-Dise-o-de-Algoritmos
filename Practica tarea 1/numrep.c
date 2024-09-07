#include <stdio.h>

void buscarPosiciones(int [], int, int, int, int, int *, int *);

void main() {
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 5, 5, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;

    int irepeticion, frepeticion;
    buscarPosiciones(arr, n, x, 0, n - 1, &irepeticion, &frepeticion);

    if (irepeticion != -1 && frepeticion != -1) {
        printf("El número %d se repite desde la posición %d hasta la posición %d\n", x, irepeticion, frepeticion);
    } else {
        printf("El número %d no se encuentra en el arreglo\n", x);
    }

}

void buscarPosiciones(int arr[], int n, int x, int inicio, int fin, int *irepeticion, int *frepeticion) {
    if (inicio > fin) {
        *irepeticion = -1;
        *frepeticion = -1;
        return;
    }

    int medio = (inicio + fin) / 2;
    if (arr[medio] == x) {
        *irepeticion = medio;
        *frepeticion = medio;
        while (*irepeticion > 0 && arr[*irepeticion - 1] == x)
            (*irepeticion)--;
        while (*frepeticion < n - 1 && arr[*frepeticion + 1] == x)
            (*frepeticion)++;
        return;
    } else if (arr[medio] < x) {
        buscarPosiciones(arr, n, x, medio + 1, fin, irepeticion, frepeticion);
    } else {
        buscarPosiciones(arr, n, x, inicio, medio - 1, irepeticion, frepeticion);
    }
}