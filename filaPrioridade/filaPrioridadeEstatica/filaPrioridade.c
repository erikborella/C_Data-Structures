#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filaPrioridade.h"

struct paciente {
    char nome[30];
    int prio;
};

struct fila_prioridade {
    int qtd;
    struct paciente dados[MAX];
};

FilaPrio* cria_FilaPrio() {
    FilaPrio* fp;
    fp = (FilaPrio*) malloc(sizeof(struct fila_prioridade));

    if (fp != NULL)
        fp->qtd = 0;
    
    return fp;
}

void libera_FilaPrio(FilaPrio* fp) {
    free(fp);
}

int tamanho_FilaPrio(FilaPrio* fp) {
    if (fp == NULL)
        return -1;
    else
        return fp->qtd;
}

int estaCheia_FilaPrio(FilaPrio* fp) {
    if (fp == NULL)
        return -1;

    return (fp->qtd == MAX);
}

int estaVazia_FilaPrio(FilaPrio* fp) {
    if (fp == NULL)
        return -1;

    return (fp->qtd == 0);
}

int insere_FilaPrio(FilaPrio* fp, char* nome, int prio) {
    if (fp == NULL)
        return 0;

    if (fp->qtd == MAX)
        return 0;

    int i = fp->qtd - 1;

    while (i >= 0 && fp->dados[i].prio >= prio) {
        fp->dados[i+1] = fp->dados[i];
        i--;
    }

    strcpy(fp->dados[i+1].nome, nome);
    fp->dados[i+1].prio = prio;
    fp->qtd++;

    return 1;
}

int remove_FilaPrio(FilaPrio* fp) {
    if (fp == NULL)
        return 0;

    if (fp->qtd == 0)
        return 0;
    
    fp->qtd--;

    return 1;
}


int consulta_FilaPrio(FilaPrio* fp, char* nome) {
    if (fp == NULL || fp->qtd == 0)
        return 0;

    strcpy(nome, fp->dados[fp->qtd-1].nome);
    return 1;
}