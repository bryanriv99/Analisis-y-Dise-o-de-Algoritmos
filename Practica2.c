#include <stdio.h>
#include <stdlib.h>

void nuevoburbuja(int *, int);
void imprimir(int *, int);
void invertir(int *, int);

int main() {
    int n = 7;
    int *A = (int*)malloc(n * sizeof(int));
    A[0] = 64; A[1] = 34; A[2] = 25; A[3] = 12; A[4] = 22; A[5] = 11; A[6] = 90;

    nuevoburbuja(A, n);
    printf("Arreglo ordenado:\n");
    imprimir(A, n);

    invertir(A, n);
    printf("\nArreglo invertido:\n");
    imprimir(A, n);

    free(A);
    return 0;
}

void invertir(int *A, int n) {
    int inicio = 0;
    int fin = n - 1;
    int temp;

    while (inicio < fin) {
        temp = A[inicio];
        A[inicio] = A[fin];
        A[fin] = temp;
        inicio++;
        fin--;
    }
}

void imprimir(int *A, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void nuevoburbuja(int *A, int n){
    int i, j, temp;
    int in;

    for (i = 0; i < n - 1; i++) {
        in = 0;
        for (j = 0; j <  n- i - 1; j++) {
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                in = 1;
            }
        }

        
        if (in == 0){
            break;
        }
    }
}