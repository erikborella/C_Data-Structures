#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *v, int n) {
    int i, j, atual;
    for (i = 1; i < n; i++) {
        atual = v[i];
        for (j = i; (j > 0) && (atual < v[j-1]); j--)
            v[j] = v[j-1];
        v[j] = atual;
    }
}

int main() {
    int n = 5, i;
    int v[] = {23, 4, 67, -8, 21};


    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }

    insertionSort(v, n);

    printf("\n\n");

    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
}