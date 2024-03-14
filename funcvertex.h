#ifndef __FUNCVERTEX_H
#define __FUNCVERTEX_H

#include "EstructuraGrafo24.h"

// Cantidad de vecinos de un vertice
u32 number_neighbors(Vertex v);

// Liberar memoria del vertice
Vertex destroy_vertex(Grafo graph,u32 i);

// Agregar los vertices al grafo
Grafo add_vertex(Grafo graph,u32 v);

#endif
