#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    int mat;
    char nome[30];
    float n1, n2, n3;
};

void insertionSortMatricula(struct aluno *v, int n) {
    int i, j;
    struct aluno aux;

    for (i = 1; i < n; i++) {
        aux = v[i];
        for (j = i; (j > 0) && (aux.mat < v[j-1].mat); j--)
            v[j] = v[j - 1];
        v[j] = aux;
    }
}

void insertionSortNome(struct aluno *v, int n) {
    int i, j;
    struct aluno aux;

    for (i = 1; i < n; i++) {
        aux = v[i];
        for (j = i; (j > 0) && (strcmp(aux.nome, v[j-1].nome) < 0); j--)
            v[j] = v[j - 1];
        v[j] = aux;
    }
}


int main() {
    int i;
    struct aluno v[4] = {{2, "Andre", 2, 2, 2},
                         {4, "Ricard", 2, 2, 2},
                         {1, "Bianca", 2, 2, 2},
                         {3, "Ana", 2, 2, 2}};
    
    insertionSortMatricula(v, 4);

    for (i = 0; i < 4; i++)
        printf("%d) %s\n", v[i].mat, v[i].nome);

    return 0;
}