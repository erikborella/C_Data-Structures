#include <stdio.h>
#include <string.h>

struct aluno {
    int mat;
    char nome[30];
    float n1, n2, n3;
};

int buscaLinearMatricula(struct aluno *v, int n, int elem) {
    int i;

    for (i = 0; i < n; i++) {   
        if (elem == v[i].mat)
            return i;
    }

    return -1;
}

int buscaLinearNome(struct aluno *v, int n, char *elem) {
    int i;

    for (i = 0; i < n; i++) {
        if (strcmp(elem, v[i].nome) == 0)
            return i;
    }

    return -1;
}

int main() {
    int n = 4;
    struct aluno v[] = {{2, "Andre", 2.0, 2.0, 2.0},
                        {4, "Ricardo", 2.0, 2.0, 2.0},
                        {1, "Bianca", 2.0, 2.0, 2.0},
                        {3, "Ana", 2.0, 2.0, 2.0}};

    int pos = buscaLinearNome(v, n, "Andr");
    if (pos != -1)
        printf("Nome Encontrado\n");
    else
        printf("Nome nao encontrado\n");
    
    return 0;
}