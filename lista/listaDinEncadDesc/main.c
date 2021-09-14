#include <stdio.h>
#include "listaDinEncadDesc.h"

int main() {
    Lista *li = cria_lista();

    struct aluno a1;
    struct aluno a2;
    struct aluno a3;
    struct aluno a4;
    struct aluno a5;

    struct aluno b;

    a1.matricula = 1;
    a2.matricula = 2;
    a3.matricula = 3;
    a4.matricula = 4;
    a5.matricula = 5;

    insere_lista_ordenada(li, a5);
    insere_lista_ordenada(li, a4);
    insere_lista_ordenada(li, a2);
    insere_lista_ordenada(li, a1);


    insere_lista_ordenada(li, a3);

    return 0;
}