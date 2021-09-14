#include <stdio.h>
#include "Complexo.h"

int main() {
    float x, y;
    Complexo *c1, *c2, *c3;

    c1 = cCriar(2, 3);
    c2 = cCriar(1, 2);

    cDividir(c1, c2, c3);

    cAcessar(c3, &x, &y);

    printf("r: %f\ni: %f\n", x, y);


    return 0;
}