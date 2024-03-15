#include "funcvertex.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

// Calcular el maximo entre 3 valores
#define MAX3(x, y, z) (MAX(MAX(x, y), z))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

u32 number_neighbors(Vertex v){
    assert(v != NULL);
    return v->cantN;
}

Grafo add_neighbors(Grafo graph,u32 V1_id,u32 V2_id){
    Vertex V1_vertex,V2_vertex;
    u32 cantN_V1,cantN_V2;

    V1_vertex = graph->vertex[V1_id];
    V2_vertex = graph->vertex[V2_id];
    cantN_V1 = number_neighbors(V1_vertex);
    cantN_V2 = number_neighbors(V2_vertex);

    // Asignamos memoria para poder agregar el nuevo vecino
    V1_vertex->neighbors = realloc(V1_vertex->neighbors, (cantN_V1 + 1) * sizeof(struct VertexSt));
    if (V1_vertex->neighbors == NULL) {
       printf("Error allocating memory to the vertex's neighbor");
        return graph;
    }

    V2_vertex->neighbors = realloc(V2_vertex->neighbors, (cantN_V2 + 1) * sizeof(struct VertexSt));
    if (V2_vertex->neighbors == NULL) {
       printf("Error allocating memory to the vertex's neighbor");
        return graph;
    }

    // Agregamos nuevo vecino a cada vertice
    V1_vertex->neighbors[cantN_V1] = V2_vertex;
    V2_vertex->neighbors[cantN_V2] = V1_vertex;
    
    // Aumentamos la cantidad de vecinos de cada vertice
    V1_vertex->cantN ++;
    V2_vertex->cantN ++;

    // Asignar nuevo delta del grafo en el caso que exista
    graph->delta = MAX3(V1_vertex->cantN,V2_vertex->cantN,graph->delta);

    // Aumentamos la cantidad de aristas del grafo
    graph->number_E++;

    return graph;
}
