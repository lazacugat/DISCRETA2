#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcgraph.h"
#include "funcvertex.h"

#define MAX_CHARS_PER_LINE 100



Grafo ConstruirGrafo(){
    char line[MAX_CHARS_PER_LINE];
    char *expected_line_prefix = "p edge ";
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

    // Verificamos que el prefijo de la linea encontrada sea la esperada
    if (strncmp(line,expected_line_prefix,7) != 0)
    {
        printf("Error in input structure");
        return NULL;
    }
    // Leemos las cantidad de vertices y aristas solicitadas
    if (sscanf(line, "p edge %u %u", &cant_V, &cant_E) != 2) {
        printf("Error in input structure");
        return NULL;
    }

    if (cant_E < 1 || cant_V < 2) {
        printf("Error in input structure");
        return NULL;
    }


    // Asignar datos a grafo
    Grafo graph = NULL;
    graph = malloc(sizeof(struct GrafoSt));
    if (graph == NULL)
    {
        printf("Error allocating memory to the graph");
        return NULL;
    }
    graph->number_E = cant_E;
    graph->delta = 0;
    graph->vertex = malloc(cant_V * sizeof(struct VertexSt));
    if (graph->vertex == NULL)
    {
        free(graph);
        printf("Error allocating memory to the graph's vertex");
        return NULL;
    }

    for (int i = 0; i < cant_E; i++)
    {
        if (fgets(line, MAX_CHARS_PER_LINE,stdin) == NULL || sscanf(line, "e %d %d", &V1, &V2) != 2)
        {
            printf("Error in input structure");
            return NULL;
        }
       // Asignamos datos de los vertices
        graph->vertex = add_vertex(graph,V1);
        graph->vertex = add_vertex(graph,V2);
    }

}

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