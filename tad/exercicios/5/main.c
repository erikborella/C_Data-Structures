#include <stdio.h>
#include "Esfera.h"

int main() {
    float r, a, v;
    Esfera *e = eCriar(8);

    a = eArea(e);
    v = eVolume(e);

    printf("Area: %f\nVolume: %f\n", a, v);


    eLiberar(e);

    return 0;
}