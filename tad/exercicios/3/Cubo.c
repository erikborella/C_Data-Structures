#include <stdlib.h>
#include <math.h>
#include "Cubo.h"

struct cubo {
    float d;
};

Cubo* cCria(float d) {
    Cubo* c = (Cubo*) malloc(sizeof(Cubo));

    if (c != NULL) {
        c->d = d;
    }

    return c;
}

void cLibera(Cubo* c) {
    free(c);
}

int cTamanho(Cubo* c, float *tam) {
    if (c == NULL)
        return 0;
    
    *tam = c->d;
    
    return 1;
}

int cArea(Cubo* c, float *a) {
    if (c == NULL)
        return 0;
    
    *a = pow(c->d, 2);

    return 1;
}

int cVolume(Cubo* c, float *v) {
    if (c == NULL)
        return 0;

    *v = pow(c->d, 3);

    return 1;
}