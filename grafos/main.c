#include "grafo.h"

int main() {

    Grafo *gr = cria_grafo(4, 2, 0);

    insereAresta(gr, 0, 1, 0, 0);
    insereAresta(gr, 1, 2, 0, 0);
    insereAresta(gr, 1, 3, 0, 0);
    insereAresta(gr, 2, 3, 0, 0);
    insereAresta(gr, 3, 3, 0, 0);

    removeAresta(gr, 1, 2, 0);
    removeAresta(gr, 1, 1, 0);

    return 0;
}