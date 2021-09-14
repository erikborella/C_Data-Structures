#include <stdio.h>
#include "filaEstatica.h"

void imprimir_fila(Fila *fi) {
    while (!fila_vazia(fi)) {
        struct aluno al;
        consulta_fila(fi, &al);
        printf("%d, ", al.matricula);
        remove_fila(fi);
    }
    printf("\n");
}

int main() {
    Fila *fi = cria_fila();

    struct aluno al1;
    struct aluno al2;
    struct aluno al3;
    struct aluno al4;

    al1.matricula = 1;
    al2.matricula = 2;
    al3.matricula = 3;
    al4.matricula = 4;

    insere_fila(fi, al1);
    insere_fila(fi, al2);
    insere_fila(fi, al3);
    insere_fila(fi, al4);

    remove_fila(fi);
    remove_fila(fi);

    insere_fila(fi, al1);
    insere_fila(fi, al2);

    // imprimir_fila(fi);

    inverter_fila(fi);

    imprimir_fila(fi);

    return 0;
}