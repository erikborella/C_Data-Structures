#include "filaUsandoListaDinEncad.h"

Fila* cria_fila() {
    return cria_lista();
}

void libera_fila(Fila *fi) {
    libera_lista(fi);
}

int consulta_fila(Fila *fi, struct aluno *al) {
    return busca_lista_pos(fi, 1, al);
}

int insere_fila(Fila *fi, struct aluno al) {
    return insere_lista_final(fi, al);
}

int remove_fila(Fila *fi) {
    return remove_lista_inicio(fi);
}

int tamanho_fila(Fila *fi) {
    return tamanho_lista(fi);
}

int fila_fazia(Fila *fi) {
    return lista_vazia(fi);
}

int fila_cheia(Fila *fi) {
    return lista_cheia(fi);
}