#include "pilhaUsandoListaDinEncad.h"

Pilha* cria_pilha() {
    return cria_lista();
}

void libera_pilha(Pilha* pi) {
    libera_lista(pi);
}

int acessa_topo_pilha(Pilha* pi, struct aluno* al) {
    return busca_lista_pos(pi, 1, al);
}

int insere_pilha(Pilha* pi, struct aluno al) {
    return insere_lista_inicio(pi, al);
}

int remove_pilha(Pilha* pi) {
    return remove_lista_inicio(pi);
}

int tamanho_pilha(Pilha* pi) {
    return tamanho_lista(pi);
}

int pilha_vazia(Pilha* pi) {
    return lista_vazia(pi);
}

int pilha_cheia(Pilha* pi) {
    return lista_cheia(pi);
}