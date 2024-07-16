#include "APIG24.h"
#include "vertex_functions.h"
#include <stdio.h>

int main() {
    Grafo G = ConstruirGrafo();
    for (u32 i = 0; i < NumeroDeVertices(G); i++)
    {
        printf("Vertex %u has %u neighbors\n", i, Grado(i, G));
    }
    DestruirGrafo(G);
    return 0;
}