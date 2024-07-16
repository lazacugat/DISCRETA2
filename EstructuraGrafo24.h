#ifndef ESTRUCTURAGRAFO24_H  
#define ESTRUCTURAGRAFO24_H  

#include <stdint.h> // To use uint32_t
#include <stdbool.h>
#include "APIG24.h"

typedef uint32_t u32;

// Define the color data type as an alias of u32
typedef u32 color;

// Define the vertex data type as a pointer to a structure
typedef struct VertexSt *Vertex;

// Structure to represent information about a vertex
struct VertexSt{
    u32 id;
    color color;
    u32 num_neighbors;
    Vertex *neighbors;
    bool used;
};

// Structure to represent information about the graph
struct GrafoSt{
    u32 num_vertices;
    u32 num_edges;
    u32 delta;
    Vertex *vertex;
};

#endif