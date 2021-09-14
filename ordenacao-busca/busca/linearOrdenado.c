#include <stdio.h>
#include <stdlib.h>

int buscaOrdenada(int *v, int n, int elem) {
    int i;

    for (i = 0; i < n; i++) {
        if (elem == v[i])
            return i;
        else if (elem < v[i])
            return -1;
    }

    return -1;
}

int main() {
    int n = 6;
    int v[] = {-8, 4, 21, 23, 54, 67, 90};

    printf("54: %d\n", buscaOrdenada(v, n, 54));
    printf("32: %d\n", buscaOrdenada(v, n, 32));

    return 0;
}
