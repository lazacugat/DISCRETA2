#ifndef __FUNCVERTEX_H
#define __FUNCVERTEX_H

#include "APIG24.h"
#include "EstructuraGrafo24.h"

// Number of neighbors of a vertex
u32 number_of_neighbors(Vertex v);

// Adds a neighbor to a vertex
Grafo add_neighbors(Grafo graph, u32 V1_id, u32 V2_id);

// Adds a vertex to a graph
Grafo add_vertex(Grafo graph, u32 v);

#endif