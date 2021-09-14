#include <stdio.h>
#include <stdlib.h>
#include "filaEstatica.h"

struct fila {
    int inicio, final, qtd;
    struct aluno dados[MAX];
};

int mod(int a, int b) {
    int r = a % b;
    return r < 0 ? r + b : r;
}

Fila* cria_fila() {
    Fila *fi;
    fi = (Fila*) malloc(sizeof(struct fila));

    if (fi != NULL) {
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

void libera_fila(Fila *fi) {
    free(fi);
}

int tamanho_fila(Fila *fi) {
    if (fi == NULL)
        return -1;
    return fi->qtd;
}

int fila_cheia(Fila *fi) {
    if (fi == NULL)
        return -1;
    if (fi->qtd == MAX)
        return 1;
    else 
        return 0;
}

int fila_vazia(Fila *fi) {
    if (fi == NULL)
        return -1;
    if (fi->qtd == 0)
        return 1;
    else
        return 0;
}

int insere_fila(Fila *fi, struct aluno al) {
    if (fi == NULL)
        return 0;
    if (fi->qtd == MAX)
        return 0;

    fi->dados[fi->final] = al;
    fi->final = (fi->final+1) % MAX;
    fi->qtd++;

    return 1;
}

int remove_fila(Fila *fi) {
    if (fi == NULL || fi->qtd == 0)
        return 0;

    fi->inicio = (fi->inicio+1) % MAX;
    fi->qtd--;
    
    return 1;
}

int consulta_fila(Fila *fi, struct aluno *al) {
    if (fi == NULL || fi->qtd == 0)
        return 0;
    
    *al = fi->dados[fi->inicio];

    return 1;
}


int inverter_fila(Fila *fi) {
    if (fi == NULL || fi->qtd == 0)
        return 0;
    
    int i = fi->inicio;
    int f = mod(fi->final -1, MAX);
    
    int swaps = fi->qtd;

    if (swaps % 2 != 0)
        swaps -= 1;

    while (swaps != 0) {
        struct aluno temp = fi->dados[i];
        fi->dados[i] = fi->dados[f];
        fi->dados[f] = temp;

        swaps -= 2;
        i = mod(i+1, MAX);
        f = mod(f-1, MAX);
    }

    return 1;
}