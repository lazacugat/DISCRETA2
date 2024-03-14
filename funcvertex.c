#include "funcvertex.h"
#include <stdlib.h>

Vertex create_vertex(u32 v){
    Vertex vertex;
    vertex->idV = v;
    vertex->gradeV = 0;
    vertex->colorV = 0;
    vertex->cantN = 0;
    vertex->neighbors = malloc(sizeof(Neighbors));
}

Grafo add_vertex(Grafo graph,u32 v){
    for (int i = 0; i < graph->number_V; i++)
    {
        if (graph->vertex[i]->idV == v)
        {
            return graph;
        }
    }
    Vertex v_aux = create_vertex(v);
    graph->vertex[graph->number_V] = v_aux;
    graph->number_V ++;
    return graph;
}