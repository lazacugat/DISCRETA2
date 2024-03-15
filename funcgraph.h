#ifndef __FUNCGRAPH_H
#define __FUNCGRAPH_H

#include "EstructuraGrafo24.h"

// Cantidad de vertices que posee el grafo
u32 NumeroDeVertices(Grafo G);

// Cantidad de aristas que posee el grafo
u32 NumeroDeLados(Grafo G);

// Devuelve ∆(G), es decir, el mayor grado del grafo
u32 Delta(Grafo G);

// Devuelve el grado de un vertice
u32 Grado(u32 i,Grafo G);

// Devuelve el color de un vertice
color Color(u32 i,Grafo G);

// Devuelve el j-esimo vecino del vertice i
u32 Vecino(u32 j,u32 i,Grafo G);

// Da valor al color de un vertice
void AsignarColor(color x,u32 i,Grafo G);

// Copiar los colores de los vertices de un grafo en un arreglo
void ExtraerColores(Grafo G,color* Color);

// Copiar los colores de un arreglo a los vertices de un grafo
void ImportarColores(color* Color,Grafo G);

// Agrega un vertice a un grafo
Grafo add_vertex(Grafo graph,u32 v);

// Construccion del grafo
Grafo ConstruirGrafo();

// Liberar memoroia del grafo
void DestruirGrafo(Grafo G);

#endif
