#include <stdio.h>
#include <stdlib.h>

int buscaLinear(int *v, int n, int elem) {
    int i;

    for (i = 0; i < n; i++) {
        if (elem == v[i])
            return i;
    }

    return -1;
}

int main() {
    int n = 6;
    int v[] = {23, 4, 67, -8, 54, 90, 21};

    printf("54: %d\n", buscaLinear(v, n, 54));
    printf("32: %d\n", buscaLinear(v, n, 32));

    return 0;
}