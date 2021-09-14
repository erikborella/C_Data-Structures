typedef struct grafo Grafo;
Grafo* cria_grafo(int nro_vert, int Gmax, int eh_ponderado);
void libera_grafo(Grafo* gr);
int insereAresta(Grafo* gr, int orig, int dest, int digrafo, float peso);
int removeAresta(Grafo* gr, int orig, int dest, int digrafo);