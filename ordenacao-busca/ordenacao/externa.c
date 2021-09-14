#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quicksort.c"

#define N 100

struct arquivo {
    FILE *f;
    int pos, MAX, *buffer;
};


void criaArquivoTeste(char *nome) {
    int i;

    FILE *f = fopen(nome, "w");
    srand(time(NULL));

    for (i = 1; i < 1000; i++)
        fprintf(f, "%d\n", rand());
    
    fprintf(f, "%d", rand());
    fclose(f);
}


void salvaArquivo(char *nome, int *v, int tam, int mudaLinhaFinal) {
    int i;
    FILE *f = fopen(nome, "a");

    for (i = 0; i < tam-1; i++)
        fprintf(f, "%d\n", v[i]);

    if (mudaLinhaFinal == 0)
        fprintf(f, "%d", v[tam-1]);
    else
        fprintf(f, "%d\n", v[tam-1]);
    
    fclose(f);
}


void preencheBuffer(struct arquivo* arq, int T) {
    int i;
    if (arq->f == NULL)
        return;
    
    arq->pos = 0;
    arq->MAX = 0;

    for (i = 0; i < T; i++) {
        if (!feof(arq->f)) {
            fscanf(arq->f, "%d", &arq->buffer[arq->MAX]);
            arq->MAX++;
        } else {
            fclose(arq->f);
            arq->f = NULL;
            break;
        }
    }
}


int procuraMenor(struct arquivo* arq, int K, int T, int* menor) {
    int i, idx = -1;

    for (i = 0; i < K; i++) {
        if (arq[i].pos < arq[i].MAX) {
            if (idx == 1)
                idx = i;
            else {
                if (arq[i].buffer[arq[i].pos] < arq[idx].buffer[arq[idx].pos])
                    idx = i;
            }
        }
    }

    if (idx != -1) {
        *menor = arq[idx].buffer[arq[idx].pos];
        arq[idx].pos++;
        if (arq[idx].pos == arq[idx].MAX)
            preencheBuffer(&arq[idx], T);
        return 1;
    } else {
        return 0;
    }
}


void merge(char *nome, int K, int T) {
    char novo[20];
    int i;
    int *saida = (int*) malloc(T * sizeof(int));
    struct arquivo *arq;
    arq = (struct arquivo*) malloc(K * sizeof(struct arquivo));

    for (i = 0; i < K; i++) {
        sprintf(novo, "Temp%d.txt", i+1);
        arq[i].f = fopen(novo, "r");
        arq[i].buffer = (int*) malloc(T * sizeof(int));
        preencheBuffer(&arq[i], T);
    }

    int menor, qtdSaida = 0;

    while (procuraMenor(arq, K, T, &menor) == 1) {
        saida[qtdSaida] = menor;
        qtdSaida++;
        if (qtdSaida == T) {
            salvaArquivo(nome, saida, T, 1);
            qtdSaida = 0;
        }
    }

    if (qtdSaida != 0)
        salvaArquivo(nome, saida, qtdSaida, 1);

    for (i = 0; i < K; i++)
        free(arq[i].buffer);
    
    free(arq);
    free(saida);
}


int criaArquivosOrdenados(char *nome) {
    int v[N];
    char novo[20];
    int K = 0, total = 0;
    FILE *f = fopen(nome, "r");

    while (!feof(f)) {
        fscanf(f, "%d", &v[total]);
        total++;

        if (total == N) {
            K++;
            sprintf(novo, "Temp%d.txt", K);
            quickSort(v, 0, N-1);
            salvaArquivo(novo, v, total, 0);
            total = 0;
        }
    }

    if (total > 0) {
        K++;
        sprintf(novo, "Temp%d.txt", K);
        quickSort(v, 0, total-1);
        salvaArquivo(novo, v, total, 0);
    }

    fclose(f);
    return K;
}


void mergeSortExterno(char *nome) {
    char novo[20];
    int K = criaArquivosOrdenados(nome);
    int i, T = (N / (K + 1));
    remove(nome);
    merge(nome, K, T);

    for (i = 0; i < K; i++) {
        sprintf(novo, "Temp%d.txt", i+1);
        remove(novo);
    }
}


int main() {
    criaArquivoTeste("dados.txt");
    mergeSortExterno("dados.txt");
    return 0;
}