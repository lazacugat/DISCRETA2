#include "APIG24.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "vertex_functions.h"

// Maximum number of characters per line from standard input that we intend to read
#define MAX_CHARS_PER_LINE 100

u32 NumeroDeVertices(Grafo G){
    assert(G != NULL);
    return G->num_vertices;
}

u32 NumeroDeLados(Grafo G){
    assert(G != NULL);
    return G->num_edges;
}

u32 Delta(Grafo G){
    assert(G != NULL);
    return G->delta;
}

u32 Grado(u32 i, Grafo G){
    u32 degree = 0;
    u32 num_vertices = NumeroDeVertices(G);
    // Check if the vertex exists
    if (i < num_vertices)
    {
        degree = G->vertex[i]->num_neighbors;
    }
    return degree;
}

color Color(u32 i, Grafo G){
    color color = UINT32_MAX;
    u32 num_vertices = NumeroDeVertices(G);
    // Check if the vertex exists
    if (i < num_vertices)
    {
        color = G->vertex[i]->color;
    }
    return color;
}

u32 Vecino(u32 j, u32 i, Grafo G){
    u32 neighbor = UINT32_MAX, num_vertices = NumeroDeVertices(G);
    // Check if the vertex and the neighbor exist
    if ((i < num_vertices) && (j < Grado(i, G)))
    {
        neighbor = G->vertex[i]->neighbors[j]->id;
    }
    return neighbor;
}

void AsignarColor(color x, u32 i, Grafo G){
    u32 num_vertices = NumeroDeVertices(G);
    // Check if the vertex exists
    if (i < num_vertices)
    {
        G->vertex[i]->color = x;
    }
}

void ExtraerColores(Grafo G, color* color_array){
    u32 num_vertices = NumeroDeVertices(G);
    for (u32 i = 0; i < num_vertices; i++)
    {
        color_array[i] = Color(i, G);
    }
}

void ImportarColores(color* color_array, Grafo G){
    u32 num_vertices = NumeroDeVertices(G);
    for (u32 i = 0; i < num_vertices; i++)
    {
        AsignarColor(color_array[i], i, G);
    }
}

// Struct to store the input data
typedef struct {
    u32 num_vertices;
    u32 num_edges;
} input_data;


// Skip commentaries in the input file
static void skip_commentaries(char* line, u32 length){
    line[0] = 'c';
    while (line[0] == 'c')
    {
        if (fgets(line, length,stdin) == NULL)
        {
            printf("Error : Incorrect input structure\n");
            exit(1);
        }
    }
}

// Read the input data and check if it is correct
static input_data read_input_data(){
    char line[MAX_CHARS_PER_LINE];

    skip_commentaries(line,MAX_CHARS_PER_LINE);
    
    input_data data;
    data.num_vertices = 0;
    data.num_edges = 0;
    
    // Read the data
    if (sscanf(line, "p edge %u %u", &data.num_vertices, &data.num_edges) != 2)
    {
        printf("Error : Incorrect input structure\n");
        exit(1);
    }

    // Check that there is at least one edge and that the number of vertices is at least 2
    if (data.num_edges < 1 || data.num_vertices < 2) {
        printf("Error : Incorrect input structure\n");
        exit(1);
    }
    return data;
}

// Initialize the vertices of the graph
static void vertices_init(Grafo graph,u32 num_vertices){
    for (u32 i = 0; i < num_vertices; i++) {
        graph->vertex[i] = malloc(sizeof(struct VertexSt));
        if (graph->vertex[i] == NULL)
        {
            free(graph);
            printf("Error: Failed to allocate memory for vertices in the graph\n");
            return exit(1);
        }
        graph->vertex[i]->id = i;
        graph->vertex[i]->num_neighbors = 0;
        graph->vertex[i]->color = 0;
        graph->vertex[i]->neighbors = NULL;
        graph->vertex[i]->used = false;
    }
}   

// Initialize the graph
static void graph_init(Grafo graph, u32 num_vertices){
    graph->num_vertices = 0;
    graph->num_edges = 0;
    graph->delta = 0;
    graph->vertex = malloc(num_vertices * sizeof(Vertex));

    if (graph->vertex == NULL)
    {
        free(graph);
        printf("Error: Failed to allocate memory for vertices in the graph\n");
        return exit(1);
    }
    vertices_init(graph, num_vertices);

}

// Add vertices to the graph
static void graph_add_vertices(Grafo graph, u32 num_vertices, u32 num_edges){
    char line[MAX_CHARS_PER_LINE];
    u32 V1, V2;
    // Read the edges
    for (u32 i = 0; i < num_edges; i++)
    {
        if (fgets(line, MAX_CHARS_PER_LINE, stdin) == NULL )
        {
            printf("Error: Incorrect input structure\n");
            return exit(1);
        }
        if (sscanf(line, "e %u %u", &V1, &V2) != 2)
        {
            printf("Error: Incorrect input structure\n");
            return exit(1);
        }
       // Add vertices to the graph
        graph = add_vertex(graph, V1);
        graph = add_vertex(graph, V2);

        // Add neighbors to the vertices
        graph = add_neighbors(graph, V1, V2);
    }

    // Check if they were added correctly
    if ((graph->num_vertices != num_vertices))
    {
            printf("Error: Failed to add vertices to the graph\n");
            return exit(1);
    }
    
    if ((graph->num_edges != num_edges))
    {
            printf("Error: Failed to add edges to the graph\n");
            return exit(1);
    }
}

// Create the graph
static Grafo graph_creation(u32 num_vertices, u32 num_edges){
    Grafo graph = malloc(sizeof(struct GrafoSt));

    if (graph == NULL)
    {
        printf("Error: Failed to allocate memory for the graph\n");
        return NULL;
    }

    graph_init(graph, num_vertices);
    graph_add_vertices(graph, num_vertices, num_edges);
    return graph;
}



Grafo ConstruirGrafo(){
    // -------- PART 1: INPUT READING
    input_data data = read_input_data();

    // -------- PART 2: GRAPH CREATION
    Grafo graph = graph_creation(data.num_vertices, data.num_edges);

    return graph;
}



void DestruirGrafo(Grafo G){
    u32 num_vertices = NumeroDeVertices(G);
    // Free the memory allocated for the neighbors of each vertex
    for (u32 i = 0; i < num_vertices; i++)
    {
        free(G->vertex[i]->neighbors);
        free(G->vertex[i]);
    }
    free(G->vertex);
    free(G);
}