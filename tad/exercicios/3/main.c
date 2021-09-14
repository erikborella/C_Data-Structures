#include <stdio.h>
#include "Cubo.h"

int main() {
    float d, a, v;
    Cubo *c;

    c = cCria(10);

    cTamanho(c, &d);
    cArea(c, &a);
    cVolume(c, &v);

    printf("Tamanho: %f\nArea: %f\nVolume: %f\n", d, a, v);


    cLibera(c);
    return 0;
}