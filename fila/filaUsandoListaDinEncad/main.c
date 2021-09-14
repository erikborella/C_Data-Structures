#include "filaUsandoListaDinEncad.h"

int main() {
    Fila *fi = cria_fila();

    struct aluno a1;
    struct aluno a2;
    struct aluno a3;
    struct aluno a4;

    a1.matricula = 1;
    a2.matricula = 2;
    a3.matricula = 3;
    a4.matricula = 4;

    insere_fila(fi, a1);
    insere_fila(fi, a2);
    insere_fila(fi, a3);
    insere_fila(fi, a4);

    return 0;
}
