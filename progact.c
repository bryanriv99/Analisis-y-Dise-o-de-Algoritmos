#include <stdio.h>
#include <stdlib.h>
int comparar()
typedef struct {
    int inicio;
    int fin;
} Actividad;


void main(){

}

int comparar(Actividad *a, actividad *b) {
    return ((Actividad*)a)->fin - ((Actividad*)b)->fin;
}

void seleccionarActividades(Actividad actividades[], int n) {
    qsort(actividades, n, sizeof(Actividad), comparar);
    int i = 0;
    printf("Actividad seleccionada: (%d, %d)\n", actividades[i].inicio, actividades[i].fin);
    for (int j = 1; j < n; j++) {
    }
}


