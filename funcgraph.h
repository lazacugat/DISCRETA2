#ifndef __FUNCGRAPH_H
#define __FUNCGRAPH_H

#include "EstructuraGrafo24.h"

// Crear vertice para un grafo
Vertex create_vertex(u32 v);

// Cantidad de vertices que posee el grafo
u32 NumeroDeVertices(Grafo G);

// Cantidad de aristas que posee el grafo
u32 NumeroDeLados(Grafo G);

// Devuelve ∆(G), es decir, el mayor grado del grafo
u32 Delta(Grafo G);

// Construccion del grafo
Grafo ConstruirGrafo();

// Liberar memoroia del grafo
void DestruirGrafo(Grafo G);


#endif
