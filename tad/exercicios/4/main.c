#include <stdio.h>
#include "Cilindro.h"

int main() {
    float h, r, a, v;
    Cilindro *c;

    c = cCria(5, 4);

    a = cArea(c);
    v = cVolume(c);

    printf("Area: %f\nVolume: %f\n", a, v);

    cLibera(c);
    return 0;
}