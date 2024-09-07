#include <stdio.h>
#include <limits.h>

int menoshumo(int [], int );

void main() {
    int colores[] = {40, 60, 20};
    int n = sizeof(colores) / sizeof(colores[0]);
    
    int r = menoshumo(colores, n);
    printf("La cantidad minima de humo es: %d\n", r);
    
}

int menoshumo(int colores[], int n) {
    int humo[n][n];
    int colornuevo[n][n];
    
    for (int i = 0; i < n; i++) {
        colornuevo[i][i] = colores[i];
        humo[i][i] = 0;
    }
    
    for (int longitud = 2; longitud <= n; longitud++) {
        for (int i = 0; i <= n - longitud; i++) {
            int j = i + longitud - 1; 
            humo[i][j] = INT_MAX;  
            
            for (int k = i; k < j; k++) {
                
                int actual = humo[i][k] + humo[k + 1][j] + colornuevo[i][k] * colornuevo[k + 1][j];
                
                if (actual < humo[i][j]) {
                    humo[i][j] = actual;
                    colornuevo[i][j] = (colornuevo[i][k] + colornuevo[k + 1][j]) % 100;
                }
            }
        }
    }
    
    return humo[0][n - 1];
}