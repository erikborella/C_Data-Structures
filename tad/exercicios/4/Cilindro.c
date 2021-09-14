#include <stdlib.h>
#include <math.h>
#include "Cilindro.h"

#define PI 3.14

struct cilindro {
    float h;
    float r;
};

Cilindro* cCria(float h, float r) {
    Cilindro *c = (Cilindro*) malloc(sizeof(Cilindro));

    if (c != NULL) {
        c->h = h;
        c->r = r;
    }

    return c;
}

void cLibera(Cilindro *c) {
    free(c);
}

int cAcessa(Cilindro *c, float *h, float *r) {
    if (c == NULL)
        return 0;

    *h = c->h;
    *r = c->r;

    return 1;
}

float cArea(Cilindro *c) {
    if (c == NULL)
        return -1;

    float ab = PI * pow(c->r, 2);
    float al = 2 * PI * c->r * c->h;

    return 2 * ab + al;
}

float cVolume(Cilindro *c) {
    if (c == NULL)
        return -1;

    return PI * pow(c->r, 2) * c->h;
}