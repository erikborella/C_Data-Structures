#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"

int main() {
    float d;
    Ponto *p, *q;

    p = Ponto_cria(10, 21);
    q = Ponto_cria(7, 25);

    d = Ponto_distancia(p, q);

    printf("Disntancia entre os pontos: %f\n", d);

    Ponto_libera(p);
    Ponto_libera(q);

    return 0;
}