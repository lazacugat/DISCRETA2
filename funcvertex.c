#include "funcvertex.h"
#include <stdlib.h>


u32 number_neighbors(Vertex v){
    assert(v != NULL);
    return v->cantN;
}

Vertex create_vertex(u32 v){
    Vertex vertex;
    vertex->idV = v;
    vertex->gradeV = 0;
    vertex->colorV = 0;
    vertex->cantN = 0;
    vertex->neighbors = NULL;
    return v;
}

Grafo add_neighbors(Grafo graph,u32 V1_id,u32 V2_id){
    Vertex V1_vertex,V2_vertex;
    
    V1_vertex = graph->vertex[V1_id];
    V1_vertex = graph->vertex[V1_id];
     
    V1_vertex->cantN ++;
    V2_vertex->cantN ++;

    V1_vertex->neighbors = realloc(V1_vertex->neighbors, V1_vertex->cantN * sizeof(Vertex));
    if (V1_vertex->neighbors == NULL) {
       printf("Error allocating memory to the vertex's neighbor");
        return graph;
    }
    V1_vertex->neighbors[V1_vertex->cantN - 1] = V2_vertex;

    V2_vertex->neighbors = realloc(V2_vertex->neighbors, V2_vertex->cantN * sizeof(Vertex));
    if (V2_vertex->neighbors == NULL) {
       printf("Error allocating memory to the vertex's neighbor");
        return graph;
    }
    V2_vertex->neighbors[V2_vertex->cantN - 1] = V1_vertex;
    
    return graph;
}
