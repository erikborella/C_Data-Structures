#include <stdio.h>
#include "listaDinEncad.h"

int main() {
    Lista *li;
    li = cria_lista();

    struct aluno a1;
    struct aluno a2;
    struct aluno a3;
    struct aluno a4;

    a1.matricula = 1;
    a2.matricula = 2;
    a3.matricula = 0;
    a4.matricula = 3;

    insere_lista_ordenada(li, a1);
    insere_lista_ordenada(li, a3);

    insere_lista_ordenada(li, a2);
    insere_lista_ordenada(li, a4);

    end:

    return 0;
}