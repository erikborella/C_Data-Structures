#include "listaSequencial.h"
#include <stdio.h>
#include <string.h>

int main() {
    Lista *li;
    li = cria_lista();

    struct aluno al;

    al.matricula = 0;
    al.n1 = 1;
    al.n2 = 1;
    al.n3 = 1;

    printf("%d\n", tamanho_lista(li));

    insere_lista_final(li, al);

    printf("%d\n", tamanho_lista(li));

    insere_lista_inicio(li, al);

    printf("%d\n", tamanho_lista(li));

    return 0;
}