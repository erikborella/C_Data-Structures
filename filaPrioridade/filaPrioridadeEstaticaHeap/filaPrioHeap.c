#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filaPrioHeap.h"

struct paciente {
    char nome[30];
    int prio;
};

struct fila_prioridade_heap {
    int qtd;
    struct paciente dados[MAX];
};

FilaPrioHeap* cria_FilaPrioHeap() {
    FilaPrioHeap* fp;

    fp = (FilaPrioHeap*) malloc(sizeof(struct fila_prioridade_heap));

    if (fp != NULL) 
        fp->qtd = 0;
    
    return fp;
}

void libera_FilaPrioHeap(FilaPrioHeap* fp) {
    free(fp);
}

int tamanho_FilaPrioHeap(FilaPrioHeap* fp) {
    if (fp == NULL)
        return -1;
    else
        return fp->qtd;
}

int estaCheia_FilaPrioHeap(FilaPrioHeap* fp) {
    if (fp == NULL)
        return -1;

    return (fp->qtd == MAX);
}

int estaVazia_FilaPrioHeap(FilaPrioHeap* fp) {
    if (fp == NULL)
        return -1;
    
    return (fp->qtd == 0);
}

void promoverElemento(FilaPrioHeap* fp, int filho) {
    int pai;
    struct paciente temp;

    pai = (filho - 1) / 2;

    while ((filho > 0) && 
            (fp->dados[pai].prio <= fp->dados[filho].prio)) {

        temp = fp->dados[filho];
        fp->dados[filho] = fp->dados[pai];
        fp->dados[pai] = temp;

        filho = pai;
        pai = (pai - 1) / 2;
    }
}

int insere_FilaPrioHeap(FilaPrioHeap* fp, char* nome, int prio) {
    if (fp == NULL)
        return 0;
    if (fp->qtd == MAX)
        return 0;

    strcpy(fp->dados[fp->qtd].nome, nome);
    fp->dados[fp->qtd].prio = prio;

    promoverElemento(fp, fp->qtd);

    fp->qtd++;

    return 1;
}

void rebaixarElemento(FilaPrioHeap* fp, int pai) {
    struct paciente temp;
    int filho = 2 * pai + 1;

    while (filho < fp->qtd) {
        if (fp->dados[filho].prio < fp->dados[filho+1].prio)
            filho++;

        if (fp->dados[pai].prio >= fp->dados[filho].prio)
            break;

        temp = fp->dados[pai];
        fp->dados[pai] = fp->dados[filho];
        fp->dados[filho] = temp;

        pai = filho;
        filho = 2 * pai + 1; 
    }
}

int remove_FilaPrioHeap(FilaPrioHeap* fp) {
    if (fp == NULL)
        return 0;
    if (fp->qtd == 0)
        return 0;

    fp->qtd--;
    fp->dados[0] = fp->dados[fp->qtd];
    rebaixarElemento(fp, 0);

    return 1;
}

int consulta_FilaPrioHeap(FilaPrioHeap* fp, char* nome) {
    if (fp == NULL || fp->qtd == 0)
        return 0;
    
    strcpy(nome, fp->dados[0].nome);

    return 1;
}
