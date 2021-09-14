#include <stdlib.h>
#include <math.h>
#include "Esfera.h"

#define PI 3.14

struct esfera {
    float r;
};

Esfera* eCriar(float r) {
    Esfera *e = (Esfera*) malloc(sizeof(Esfera));

    if (e != NULL)
        e->r = r;

    return e;
}

void eLiberar(Esfera *e) {
    free(e);
}

int eAcessar(Esfera *e, float *r) {
    if (e == NULL)
        return 0;

    *r = e->r;

    return 1;
}

float eArea(Esfera *e) {
    if (e == NULL)
        return 0;

    return 4 * PI * pow(e->r, 2);
}

float eVolume(Esfera *e) {
    if (e == NULL)
        return 0;

    return 4 * PI * pow(e->r, 3) / 3;
}