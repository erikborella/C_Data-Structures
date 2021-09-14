#include <stdio.h>
#include <stdlib.h>

int particiona(int *v, int inicio, int final) {
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = v[inicio];

    while (esq < dir) {
        while (v[esq] <= pivo)
            esq++;
        while (v[dir] > pivo)
            dir--;
        
        if (esq < dir) {
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }

    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}

void quickSort(int *v, int inicio, int fim) {
    int pivo;
    if (fim > inicio) {
        pivo = particiona(v, inicio, fim);
        quickSort(v, inicio, pivo-1);
        quickSort(v, pivo+1, fim);
    }
}

int main() {
    int n = 5, i;
    int v[] = {23, 4, 67, -8, 21};


    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }

    quickSort(v, 0, n-1);

    printf("\n\n");

    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
}