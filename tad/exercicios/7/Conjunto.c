#include <stdlib.h>
#include "Vector.h"
#include "Conjunto.h"

struct conjunto {
    Vector *v;
};

Conjunto* cCriar() {
    Conjunto *c = (Conjunto*) malloc(sizeof(Conjunto));

    if (c != NULL) {
        c->v = vCriar();        
    }    

    return c;
}

void cLiberar(Conjunto *c) {
    if (c != NULL) {
        vLiberar(c->v);
        free(c);
    }
}

int cPertence(Conjunto *c, int val) {
    if (c == NULL)
        return -2;
    
    int i, size, vVal;

    vSize(c->v, &size);
    
    for (i = 0; i < size; i++) {
        vGet(c->v, i, &vVal);
        if (vVal == val)
            return i;
    }

    return -1;
}

int cInserir(Conjunto *c, int val) {
    if (c == NULL)
        return -1;

    int status;

    if (cPertence(c, val) == -1)
        status = vPush(c->v, val);
    else
        status = 0;

    return status;
}

int cRemover(Conjunto *c, int i, int *val) {
    if (c == NULL)
        return 0;

    return vRemove(c->v, i, val);
}

int cInterseccao(Conjunto *c1, Conjunto *c2, Conjunto **res) {
    if (c1 == NULL || c2 == NULL)
        return 0;

    int i, size, val;

    cLiberar(*res);
    *res = cCriar();

    vSize(c1->v, &size);

    for (i = 0; i < size; i++) {
        vGet(c1->v, i, &val);
        if (cPertence(c2, val) != -1)
            cInserir(*res, val);
    }
        
    return 1;
}

int cDiferenca(Conjunto *c1, Conjunto *c2, Conjunto **res) {
    if (c1 == NULL || c2 == NULL)
        return 0;

    int i, size, val;

    cLiberar(*res);
    *res = cCriar();

    vSize(c1->v, &size);

    for (i = 0; i < size; i++) {
        vGet(c1->v, i, &val);
        if (cPertence(c2, val) == -1)
            cInserir(*res, val);
    }

    return 1;
}

int cUniao(Conjunto *c1, Conjunto *c2, Conjunto **res) {
    if (c1 == NULL || c2 == NULL)
        return 0;

    int i, size, val;

    cLiberar(*res);
    *res = cCriar();

    vSize(c1->v, &size);

    for (i = 0; i < size; i++) {
        vGet(c1->v, i, &val);
        cInserir(*res, val);
    }

    vSize(c2->v, &size);

    for (i = 0; i < size; i++) {
        vGet(c2->v, i, &val);
        cInserir(*res, val);
    }

    return 1;
}

int cMenor(Conjunto *c, int *val) {
    if (c == NULL)
        return 0;

    int i, size, temp, menor;

    vSize(c->v, &size);
    vGet(c->v, 0, &menor);

    for (i = 1; i < size; i++) {
        vGet(c->v, i, &temp);
        if (temp < menor)
            menor = temp;
    }

    *val = menor;

    return 1;
}

int cMaior(Conjunto *c, int *val) {
    if (c == NULL)
        return 0;

    int i, size, temp, maior;

    vSize(c->v, &size);
    vGet(c->v, 0, &maior);

    for (i = 1; i < size; i++) {
        vGet(c->v, i, &temp);
        if (temp > maior)
            maior = temp;
    }

    *val = maior;

    return 1;
}

int cTamanho(Conjunto *c, int *val) {
    if (c == NULL)
        return 0;

    vSize(c->v, val);
}

int cEhIgual(Conjunto *c1, Conjunto *c2) {
    if (c1 == NULL || c2 == NULL)
        return -1;

    int size1, size2, i, val;

    cTamanho(c1, &size1);
    cTamanho(c2, &size2);

    if (size1 != size2)
        return 0;

    for (i = 0; i < size1; i++) {
        vGet(c1->v, i, &val);
        if (cPertence(c2, val) == -1)
            return 0;
    }

    return 1;
}

int cEhVazio(Conjunto *c) {
    if (c == NULL)
        return -1;

    int size;

    cTamanho(c, &size);

    return (size == 0) ? 0:1;
}
