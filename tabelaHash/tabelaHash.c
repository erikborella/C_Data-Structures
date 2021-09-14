#include <stdlib.h>
#include <string.h>

#include "tabelaHash.h"

struct hash {
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};


Hash* cria_hash(int tamanho) {
    Hash* ha = (Hash*) malloc(sizeof(Hash));

    if (ha != NULL) {
        int i;

        ha->TABLE_SIZE = tamanho;
        ha->itens = (struct aluno**) malloc(tamanho * sizeof(struct aluno*));

        if (ha->itens == NULL) {
            free(ha);
            return NULL;
        }

        ha->qtd = 0;

        for (i = 0; i < ha->TABLE_SIZE; i++)
            ha->itens[i] = NULL;
    }

    return ha;
}

void libera_hash(Hash* ha) {
    if (ha != NULL) {
        int i;

        for (i=0; i < ha->TABLE_SIZE; i++) {
            if (ha->itens[i] != NULL)
                free(ha->itens[i]);
        }

        free(ha->itens);
        free(ha);
    }
}

int chave_divisao(int chave, int TABLE_SIZE) {
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

int valor_string(char *str) {
    int i, valor = 7;
    int tam = strlen(str);

    for (i = 0; i < tam; i++)
        valor = 31 * valor + (int) str[i];

    return valor;
}

int insereHash_semColisao(Hash* ha, struct aluno al) {
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;

    int chave = al.matricula;
    int pos = chave_divisao(chave, ha->TABLE_SIZE);

    struct aluno* novo;
    novo = (struct aluno*) malloc(sizeof(struct aluno));

    if (novo == NULL)
        return 0;

    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;

    return 1;
}

int buscaHash_semColisao(Hash* ha, int mat, struct aluno* al) {
    if (ha == NULL)
        return 0;

    int pos = chave_divisao(mat, ha->TABLE_SIZE);

    if (ha->itens[pos] == NULL)
        return 0;

    *al = *(ha->itens[pos]);

    return 1;    
}

int sondagem_linear(int pos, int i, int TABLE_SIZE) {
    return ((pos + 1) & 0X7FFFFFFF) & TABLE_SIZE;
}

int insereHash_enderAberto(Hash* ha, struct aluno al) {
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    
    int chave = al.matricula;

    int i, pos, newPos;
    pos = chave_divisao(chave, ha->TABLE_SIZE);

    for (i = 0; i < ha->TABLE_SIZE; i++) {
        newPos = sondagem_linear(pos, i, ha->TABLE_SIZE);

        if (ha->itens[newPos] == NULL) {
            struct aluno* novo;
            novo = (struct aluno*) malloc(sizeof(struct aluno));

            if (novo == NULL)
                return 0;
            
            *novo = al;
            ha->itens[newPos] = novo;
            ha->qtd++;

            return 1;
        }
    }

    return 0;
}

int buscaHash_enderAberto(Hash* ha, int mat, struct aluno* al) {
    if (ha == NULL)
        return 0;

    int i, pos, newPos;
    pos = chave_divisao(mat, ha->TABLE_SIZE);

    for (i = 0; i < ha->TABLE_SIZE; i++) {
        newPos = sondagem_linear(pos, i, ha->TABLE_SIZE);

        if (ha->itens[newPos] == NULL)
            return 0;
        
        if (ha->itens[newPos]->matricula == mat) {
            *al = *(ha->itens[newPos]);
            return 1;
        }
    }

    return 0;
}