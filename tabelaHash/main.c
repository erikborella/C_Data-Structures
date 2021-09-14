#include <stdio.h>

#include "tabelaHash.h"

int main() {
    // Hash* ha = cria_hash(7);

    // struct aluno al1;
    // al1.matricula = 1;
    

    // struct aluno al2;
    // al2.matricula = 2;

    // struct aluno al3;
    // al3.matricula = 3;

    // insereHash_semColisao(ha, al1);
    // insereHash_semColisao(ha, al2);
    // insereHash_semColisao(ha, al3);

    // struct aluno temp;

    // buscaHash_semColisao(ha, al1.matricula, &temp);


    int valor = -317;

    valor = valor & 0X7FFFFFFF;

    printf("%d\n", valor);

    return 0;
}