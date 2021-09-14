#include <stdio.h>
#include "Conjunto.h"

int main() {
    Conjunto *c1, *c2, *res;
    int temp;

    c1 = cCriar();
    c2 = cCriar();

    cInserir(c1, 2);
    cInserir(c1, 666);
    cInserir(c1, 1);
    cInserir(c1, 4);

    cInserir(c2, 2);
    cInserir(c2, 666);
    cInserir(c2, 1);
    cInserir(c2, 4);

    temp = cEhIgual(c1, c2);

    return 0;
}