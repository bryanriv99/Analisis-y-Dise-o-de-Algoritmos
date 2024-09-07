#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

typedef struct {
    int origen;
    int destino;
    int peso;
} Vertice;

void imprimirRuta(int[], int);
void camino(Vertice[], int, int, int, int);

void main() {
    FILE *archivo;
    int n, m = 0;
    int origen = 0, destino = 0;
    Vertice vertices[MAX];

    archivo = fopen("ciudades.txt", "r");
    if (archivo == NULL) {
        printf("No se puede abrir el archivo.\n");
        return;
    }

    if (fscanf(archivo, "%d", &n) != 1 || fscanf(archivo, "%d %d", &origen, &destino) != 2) {
        printf("Error al leer el archivo.\n");
        fclose(archivo);
        return;
    }

    origen--;  // Ajuste para índice 0
    destino--;  // Ajuste para índice 0

    int ciudad1, ciudad2, distancia;
    while (fscanf(archivo, "%d %d %d", &ciudad1, &ciudad2, &distancia) == 3) {
        vertices[m].origen = ciudad1 - 1;
        vertices[m].destino = ciudad2 - 1;
        vertices[m].peso = distancia;
        m++;
    }

    fclose(archivo);

    camino(vertices, n, m, origen, destino);
}

void imprimirRuta(int padre[], int j) {
    int ruta[MAX]; 
    int indice = 0; 

    while (j != -1) { 
        ruta[indice++] = j;
        j = padre[j];
    }

    for (int i = indice - 1; i >= 0; i--) {
        printf("%d ", ruta[i] + 1);
    }
}


void camino(Vertice vertices[], int n, int m, int origen, int destino) {
    if (origen < 0 || origen >= n || destino < 0 || destino >= n) {
        printf("Error: Alguna de las cuidades a buscar no esta en la lista.\n");
        return;
    }

    int distancias[MAX];
    int padre[MAX];

    for (int i = 0; i < n; i++) {
        distancias[i] = INF;
        padre[i] = -1;
    }

    distancias[origen] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = vertices[j].origen;
            int v = vertices[j].destino;
            int peso = vertices[j].peso;

            if (distancias[u] != INF && distancias[u] + peso < distancias[v]) {
                distancias[v] = distancias[u] + peso;
                padre[v] = u;
            }
        }
    }

    if (distancias[destino] == INF) {
        printf("No hay camino desde la ciudad %d a la ciudad %d\n", origen + 1, destino + 1);
    } else {
        printf("Distancia minima de %d a %d: %d\n", origen + 1, destino + 1, distancias[destino]);
        printf("Ruta: ");
        imprimirRuta(padre, destino);
        printf("\n");
    }
}