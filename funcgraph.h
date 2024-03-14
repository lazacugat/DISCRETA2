#ifndef __FUNCGRAPH_H
#define __FUNCGRAPH_H

#include "EstructuraGrafo24.h"

// Construccion del grafo
Grafo ConstruirGrafo();

// Devuelve el numero de vertices
u32 NumeroDeVertices(Grafo G);

// Devuelve el n ́umero de lados de G
u32 NumeroDeLados(Grafo G);

// Devuelve ∆(G), es decir, el mayor grado
u32 Delta(Grafo G);

#endif