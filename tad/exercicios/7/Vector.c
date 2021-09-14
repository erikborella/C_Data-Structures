#include <stdlib.h>
#include <stdio.h>
#include "Vector.h"

struct vector {
    int *v;
    int maxSize;
    int ptr;
};

Vector* vCriar() {
    Vector *v;
    v = (Vector *) malloc(sizeof(Vector));

    if (v != NULL) {
        v->v = malloc(sizeof(int) * 1);
        v->maxSize = 1;
        v->ptr = 0;
    }

    return v;
}

void vLiberar(Vector *v) {
    if (v != NULL) {
        free(v->v);
        free(v);
    }
}

int vGet(Vector *v, int i, int *val) {
    if (v == NULL)
        return -1;

    if (i >= v->ptr || i < 0)
        return 0;

    *val = v->v[i];

    return 1;
}

int vPush(Vector *v, int n) {
    if (v == NULL)
        return 0;

    if (v->ptr == v->maxSize) {
        v->maxSize *= 2;
        v->v = realloc(v->v, sizeof(int) * v->maxSize);
    }

    v->v[v->ptr] = n;
    v->ptr++;

    return 1;
}

int vRemove(Vector *v, int i, int *val) {
    if (v == NULL)
        return -1;

    if (i < 0 || i >= v->ptr)
        return 0;

    int j;
    *val = v->v[i];

    for (j = i; j < v->ptr-1; j++)
        v->v[j] = v->v[j+1];

    v->ptr--;

    return 0;
}

int vSize(Vector *v, int *val) {
    if (v == NULL)
        return 0;

    *val = v->ptr;
    return 1;
}