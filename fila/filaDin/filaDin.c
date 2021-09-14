#include <stdio.h>
#include <stdlib.h>
#include "filaDin.h"

struct elemento {
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

struct fila {
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Fila* cria_fila() {
    Fila *fi = (Fila*) malloc(sizeof(struct fila));
    if (fi != NULL) {
        fi->inicio = NULL;
        fi->final = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_fila(Fila *fi) {
    if (fi != NULL) {
        Elem *no;
        while (fi->inicio != NULL) {
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int tamanho_fila(Fila *fi) {
    if (fi == NULL)
        return 0;
    return fi->qtd;
}

int fila_cheia(Fila *fi) {
    return 0;
}

int fila_vazia(Fila *fi) {
    if (fi == NULL)
        return -1;
    if (fi->inicio == NULL)
        return 1;
    return 0;
}

int insere_fila(Fila *fi, struct aluno al) {
    if (fi == NULL)
        return 0;
    
    Elem *no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL)
        return 0;
    
    no->dados = al;
    no->prox = NULL;

    if (fi->final == NULL)
        fi->inicio = no;
    else
        fi->final->prox = no;

    fi->final = no;
    fi->qtd++;

    return 1;
}

int remove_fila(Fila *fi) {
    if (fi == NULL)
        return 0;

    if (fi->inicio == NULL)
        return 0;
    
    Elem *no = fi->inicio;

    fi->inicio = fi->inicio->prox;
    free(no);

    if (fi->inicio == NULL)
        fi->final = NULL;

    fi->qtd--;

    return 1;
}

int consulta_fila(Fila *fi, struct aluno *al) {
    if (fi == NULL)
        return 0;
    if (fi->inicio == NULL)
        return 0;

    *al = fi->inicio->dados;

    return 1;
}


int inverter_fila(Fila *fi) {
    if (fi == NULL)
        return 0;
    
    if (fi->inicio == NULL)
        return 0;

    int swaps = fi->qtd;

    if (swaps % 2 != 0)
        swaps -= 1;

    if (fi->inicio == fi->final)
        return 1;

    Elem *i = fi->inicio;
    Elem *f = fi->final;

    while (swaps != 0) {
        struct aluno temp = i->dados;
        i->dados = f->dados;
        f->dados = temp;
        
        i = i->prox;

        Elem *ant = fi->inicio;

        while (ant->prox != f)
            ant = ant->prox;

        f = ant;

        swaps -= 2;
    }

    return 1;
}