#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *v, int n) {
    int i, continua, aux, fim = n;

    do {
        continua = 0;
        for (i = 0; i < fim-1; i++) {
            if (v[i] > v[i+1]) {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = i;
            }
        }
        fim--;
    } while (continua != 0);
}

int main() {
    int n = 5, i;
    int v[] = {23, 4, 67, -8, 21};

    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }

    bubbleSort(v, n);

    printf("\n\n");

    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
}