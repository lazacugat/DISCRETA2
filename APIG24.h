#ifndef APIG24_H
#define APIG24_H

#include <stdio.h>
#include <stdlib.h>
#include "EstructuraGrafo24.h"

typedef struct GrafoSt *Grafo;

// Construction of a graph from a file.
Grafo ConstruirGrafo();

// Destruction of a graph.
void DestruirGrafo(Grafo G);

// Functions to extract data from the graph.
u32 NumeroDeVertices(Grafo G);
u32 NumeroDeLados(Grafo G);
u32 Delta(Grafo G);

// Functions for extracting information from vertices.
u32 Grado(u32 i, Grafo G);
color Color(u32 i, Grafo G);
u32 Vecino(u32 j, u32 i, Grafo G);

// Functions with colors.
void AsignarColor(color x, u32 i, Grafo G);
void ExtraerColores(Grafo G, color* Color);
void ImportarColores(color* Color, Grafo G);

#endif
