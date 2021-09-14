#include "../../lista/listaDinEncad/listaDinEncad.h"

typedef Lista Pilha;

Pilha* cria_pilha();
void libera_pilha(Pilha* pi);
int acessa_topo_pilha(Pilha* pi, struct aluno* al);
int insere_pilha(Pilha* pi, struct aluno al);
int remove_pilha(Pilha* pi);
int tamanho_pilha(Pilha* pi);
int pilha_vazia(Pilha* pi);
int pilha_cheia(Pilha* pi);