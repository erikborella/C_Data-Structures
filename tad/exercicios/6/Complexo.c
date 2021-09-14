#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Complexo.h"

struct complexo {
    float x;
    float y;
};

Complexo* cCriar(float x, float y) {
    Complexo *c = (Complexo*) malloc(sizeof(Complexo));

    if (c != NULL) {
        c->x = x;
        c->y = y;
    }

    return c;
}

void cLiberar(Complexo *c) {
    free(c);
}

int cAcessar(Complexo *c, float *x, float *y) {
    if (c == NULL)
        return 0;
    
    *x = c->x;
    *y = c->y;

    return 1;
}

int cSomar(Complexo *c1, Complexo *c2, Complexo *res) {
    if (c1 == NULL || c2 == NULL) 
        return 0;

    float x = c1->x + c2->x;
    float y = c1->y + c2->y;

    if (res == NULL)
        res = cCriar(x, y);
    else {
        res->x = x;
        res->y = y;
    }

    return 1;
}

int cSubtrair(Complexo *c1, Complexo *c2, Complexo *res) {
    if (c1 == NULL || c2 == NULL) 
        return 0;

    float x = c1->x - c2->x;
    float y = c1->y - c2->y;

    if (res == NULL)
        res = cCriar(x, y);
    else {
        res->x = x;
        res->y = y;
    }

    return 1;
}

int cMultiplicar(Complexo *c1, Complexo *c2, Complexo *res) {
    if (c1 == NULL || c2 == NULL) 
        return 0;


    float x = (c1->x * c2->x) - (c1->y * c2->y);
    float y = (c1->x * c2->y) + (c1->y * c2->x);

    
    if (res == NULL) {
        res = cCriar(x, y);
    }
    else {
        res->x = x;
        res->y = y;
    }

    return 1;
}

int cDividir(Complexo *c1, Complexo *c2, Complexo *res) {
    if (c1 == NULL || c2 == NULL)
        return 0;

    float x, y;
    Complexo *c3 = cCriar(0, 0), *c4 = cCriar(0, 0);
    Complexo *conj = cCriar(c2->x, c2->y * -1);

    cMultiplicar(c1, conj, c3);
    cMultiplicar(c2, conj, c4);

    x = c3->x / c4->x;
    y = c3->y / c4->x;

    if (res == NULL)
        res = cCriar(x, y);
    else {
        res->x = x;
        res->y = y;
    }

    cLiberar(c3);
    cLiberar(c4);
    cLiberar(conj);

    return 1;
}