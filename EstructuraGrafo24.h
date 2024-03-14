#include <stdint.h> // Para usar uint32_t
#include <stdbool.h>

typedef uint32_t u32;

// Definimos el tipo de dato color como un alias de u32
typedef u32 color;

typedef struct GrafoSt *Grafo;

typedef struct VertexSt *Vertex;

// Estructura para representar la informacion sobre un vertice
struct VertexSt{
    u32 idV;
    u32 gradeV;
    color colorV;
    u32 cantN;
    Vertex *neighbors;
};

// Estructura para representar la informacion sobre el grafo 
struct GrafoSt{
    u32 number_V;
    u32 number_E;
    u32 delta;
    Vertex *vertex;
};
