#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *v, int n) {
    int i, j, menor, troca;

    for (i = 0; i < n-1; i++) {
        menor = i;
        for (j = i+1; j < n; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        if (menor != i) {
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}

int main() {
    int n = 5, i;
    int v[] = {23, 4, 67, -8, 21};


    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }

    selectionSort(v, n);

    printf("\n\n");

    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
}