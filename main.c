#include "funcgraph.h"
#include "funcvertex.h"
#include <stdio.h>

int main(){
    Grafo G = ConstruirGrafo();
    DestruirGrafo(G);
    return 0;
}
