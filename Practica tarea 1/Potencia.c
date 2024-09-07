#include <stdio.h>

int potencia(int, int);

void main() {
    int x, n;
    printf("Ingrese el valor de x: ");
    scanf("%d", &x);
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    int resultado = potencia(x, n);
    printf("%d elevado a la %d es: %d\n", x, n, resultado);
}

int potencia(int x, int n) {
    if (n == 0)
        return 1;
    else if (n % 2 == 0) {
        int mitad = potencia(x, n / 2);
        return mitad * mitad;
    } else {
        int mitad = potencia(x, (n - 1) / 2);
        return x * mitad * mitad;
    }
}