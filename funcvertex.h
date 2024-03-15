#ifndef __FUNCVERTEX_H
#define __FUNCVERTEX_H

#include "EstructuraGrafo24.h"

// Cantidad de vecinos de un vertice
u32 number_neighbors(Vertex v);

// Agrega un vecinos a un vertice
Grafo add_neighbors(Grafo graph,u32 V1_id,u32 V2_id);

#endif
