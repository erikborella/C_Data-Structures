#define MAX 100

typedef struct fila_prioridade_heap FilaPrioHeap;

FilaPrioHeap* cria_FilaPrioHeap();
void libera_FilaPrioHeap(FilaPrioHeap* fp);
int consulta_FilaPrioHeap(FilaPrioHeap* fp, char* nome);
int insere_FilaPrioHeap(FilaPrioHeap* fp, char* nome, int prio);
int remove_FilaPrioHeap(FilaPrioHeap* fp);
int tamanho_FilaPrioHeap(FilaPrioHeap* fp);
int estaCheia_FilaPrioHeap(FilaPrioHeap* fp);
int estaVazia_FilaPrioHeap(FilaPrioHeap* fp);
