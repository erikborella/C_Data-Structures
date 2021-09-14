#include "../../lista/listaDinEncad/listaDinEncad.h"

typedef Lista Fila;

Fila* cria_fila();
void libera_fila(Fila *fi);
int consulta_fila(Fila *fi, struct aluno *al);
int insere_fila(Fila *fi, struct aluno al);
int remove_fila(Fila *fi);
int tamanho_fila(Fila *fi);
int fila_vazia(Fila *fi);
int fila_cheia(Fila *fi);