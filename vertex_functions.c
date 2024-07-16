#include "APIG24.h"
#include "vertex_functions.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

// Calculate the maximum among 3 values
#define MAX3(x, y, z) (MAX(MAX(x, y), z))
// Calculate the maximum between 2 values
#define MAX(x, y) ((x) > (y) ? (x) : (y))

u32 number_of_neighbors(Vertex vertex){
    assert(vertex != NULL);
    return vertex->num_neighbors;
}

Grafo add_neighbors(Grafo graph, u32 vertex1_id, u32 vertex2_id){
    Vertex vertex1 = graph->vertex[vertex1_id];
    Vertex vertex2 = graph->vertex[vertex2_id];

    // Reallocate memory to add the new neighbor to vertex1
    vertex1->neighbors = realloc(vertex1->neighbors, (vertex1->num_neighbors + 1) * sizeof(Vertex));
    if (vertex1->neighbors == NULL) {
       printf("Error: Memory allocation failed for the vertex's neighbor\n");
        return graph;
    }

    // Reallocate memory to add the new neighbor to vertex2
    vertex2->neighbors = realloc(vertex2->neighbors, (vertex2->num_neighbors + 1) * sizeof(Vertex));
    if (vertex2->neighbors == NULL) {
       printf("Error: Memory allocation failed for the vertex's neighbor\n");
        return graph;
    }

    // Add new neighbor to each vertex
    vertex1->neighbors[vertex1->num_neighbors] = vertex2;
    vertex2->neighbors[vertex2->num_neighbors] = vertex1;
    
    // Increase the number of neighbors for each vertex
    vertex1->num_neighbors++;
    vertex2->num_neighbors++;

    // Assign new delta to the graph if it exists
    graph->delta = MAX3(vertex1->num_neighbors, vertex2->num_neighbors, graph->delta);

    // Increase the number of edges in the graph
    graph->num_edges++;

    return graph;
}


Grafo add_vertex(Grafo graph,u32 v){

    // Check if the vertex already belongs to the graph, if so, do nothing
    if (graph->vertex[v]->used == true)
    {
        return graph;
    }

    // If the vertex does not belong to the graph, create it and add it
    graph->vertex[v]->used = true;

    // Increase the number of vertices in the graph
    graph->num_vertices ++;
    
    return graph;
}