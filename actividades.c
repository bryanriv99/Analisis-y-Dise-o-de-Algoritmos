#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Actividad {
    char nombre[50];
    int inicio, fin;
};


int compararPorFin(const void* a, const void* b) {
    struct Actividad *actividadA = (struct Actividad *)a;
    struct Actividad *actividadB = (struct Actividad *)b;
    return (actividadA->fin - actividadB->fin);
}


void seleccionarActividades(struct Actividad actividades[], int n) {
    // Ordenar actividades por tiempo de finalización
    qsort(actividades, n, sizeof(struct Actividad), compararPorFin);
    
    printf("Actividades seleccionadas:\n");
    
    // Seleccionar la primera actividad
    int i = 0;
    printf("(%s: %d, %d)\n", actividades[i].nombre, actividades[i].inicio, actividades[i].fin);
    

    for (int j = 1; j < n; j++) {
        if (actividades[j].inicio >= actividades[i].fin) {
            printf("(%s: %d, %d)\n", actividades[j].nombre, actividades[j].inicio, actividades[j].fin);
            i = j;
        }
    }
}

int main() {
    struct Actividad actividades[] = {{"Reunión", 1, 3}, {"Presentación", 2, 4}, {"Entrevista", 3, 5}, {"Conferencia", 4, 7}, {"Almuerzo", 6, 9}, {"Networking", 8, 10}};
    int n = sizeof(actividades) / sizeof(actividades[0]);
    
    seleccionarActividades(actividades, n);
    
    return 0;
}
