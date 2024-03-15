#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "funcgraph.h"
#include "funcvertex.h"

// Numero maximo de caracteres por linea del standar input que pretendemos leer
#define MAX_CHARS_PER_LINE 100

u32 NumeroDeVertices(Grafo G){
    assert(G != NULL);
    return G->number_V;
}

u32 NumeroDeLados(Grafo G){
    assert(G != NULL);
    return G->number_E;
}

u32 Delta(Grafo G){
    assert(G != NULL);
    return G->delta;
}

u32 Grado(u32 i,Grafo G){
    u32 grade = 0,cantV = NumeroDeVertices(G);
    if (i < cantV)
    {
        grade = G->vertex[i]->cantN;
    }
    return grade;
}

color Color(u32 i,Grafo G){
    color color = UINT32_MAX;
    u32 cantV = NumeroDeVertices(G);
    if (i < cantV)
    {
        color = G->vertex[i]->colorV;
    }
    return color;
}

u32 Vecino(u32 j,u32 i,Grafo G){
    u32 neighbor = UINT32_MAX,cantV = NumeroDeVertices(G);
    if ((i < cantV) && (j < Grado(i,G)))
    {
        neighbor = G->vertex[i]->neighbors[j]->idV;
    }
    return neighbor;
}

void AsignarColor(color x,u32 i,Grafo G){
    u32 cantV = NumeroDeVertices(G);
    if (i < cantV)
    {
        G->vertex[i]->colorV = x;
    }
}

void ExtraerColores(Grafo G,color* Colorarray){
    u32 cantV = NumeroDeVertices(G);
    for (u32 i = 0; i < cantV; i++)
    {
        Colorarray[i] = Color(i,G);
    }
}

void ImportarColores(color* Color,Grafo G){
    u32 cantV = NumeroDeVertices(G);
    for (u32 i = 0; i < cantV; i++)
    {
        AsignarColor(Color[i],i,G);
    }
}

Grafo add_vertex(Grafo graph,u32 v){

    // Buscamos si el vertice ya pertenece al grafico, de ser asi no hacemos nada
    if (graph->vertex[v]->used == true)
    {
        return graph;
    }

    // Si el vertice no pertenecia al grafo, lo creamos y lo agregamos
    graph->vertex[v]->used = true;

    graph->number_V ++;
    

    return graph;
}

Grafo ConstruirGrafo(){

    // -------- PARTE 1 : LECTURA DEL INPUT
    
    
    char line[MAX_CHARS_PER_LINE];
    
    line[0] = 'c';

    u32 cant_V = 0;
    u32 cant_E = 0;
    u32 V1,V2;
    
    // Ignoramos todas aquellas lineas que poseen el char 'c'
    while (line[0] == 'c')
    {
        if (fgets(line, MAX_CHARS_PER_LINE,stdin) == NULL)
        {
            printf("Error in input structure");
            return NULL;
        }
    }

    // Leemos las cantidad de vertices y aristas solicitadas
    if (sscanf(line, "p edge %u %u", &cant_V, &cant_E) != 2) {
        printf("Error : Input structure\n");
        return NULL;
    }

    // Verificamos que exista al menos una aristas y que la cantidad de vertices sea al menos 2
    if (cant_E < 1 || cant_V < 2) {
        printf("Error : Input structure\n");
        return NULL;
    }

    // -------- PARTE 2 : CREACION DEL GRAFO 

    Grafo graph = NULL;
    graph = malloc(sizeof(struct GrafoSt));
    if (graph == NULL)
    {
        printf("Error : Failed in allocating memory to the graph\n");
        return NULL;
    }

    // Inicializamos el grafo
    graph->number_V = 0;
    graph->number_E = 0;
    graph->delta = 0;
    graph->vertex = malloc(cant_V * sizeof(Vertex));

    if (graph->vertex == NULL)
    {
        free(graph);
        printf("Error: Failed to allocate memory for vertex in the graph\n");
        return NULL;
    }

    // Asignamos memoria a cada vertice
    for (u32 i = 0; i < cant_V; i++) {
        graph->vertex[i] = malloc(sizeof(struct VertexSt));
        if (graph->vertex[i] == NULL)
        {
            free(graph);
            printf("Error: Failed to allocate memory for vertex in the graph\n");
            return NULL;
        }
        graph->vertex[i]->idV = i;
        graph->vertex[i]->cantN = 0;
        graph->vertex[i]->colorV = 0;
        graph->vertex[i]->neighbors = NULL;
        graph->vertex[i]->used = false;
    }

    // Agregamos vertices y vecinos
    for (u32 i = 0; i < cant_E; i++)
    {
        if (fgets(line, MAX_CHARS_PER_LINE,stdin) == NULL )
        {
            printf("Error : Input structure2\n");
            return NULL;
        }
        if (sscanf(line, "e %u %u", &V1, &V2) != 2)
        {
            printf("Error : Input structure1\n");
            return NULL;
        }
       // Agregamos los vertices al grafo
        graph = add_vertex(graph,V1);
        graph = add_vertex(graph,V2);

        // Agrgegamos los vecinos a los vertices
        graph = add_neighbors(graph,V1,V2);
    }


    // Verificamos que se hayan agregado correctamente
    if ((graph->number_V != cant_V))
    {
            printf("Error : Failed to add vertex to the graph \n");
            return NULL;
    }
    
    if ((graph->number_E != cant_E))
    {
            printf("Error : Failed to add edge to the graph \n");
            return NULL;
    }

    return graph;
}



void DestruirGrafo(Grafo G){
    u32 cant_V = NumeroDeVertices(G);
    for (u32 i = 0; i < cant_V; i++)
    {
        free(G->vertex[i]->neighbors);
        free(G->vertex[i]);
    }
    free(G->vertex);
    free(G);
}
