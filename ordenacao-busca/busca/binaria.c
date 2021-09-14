#include <stdio.h>

int buscaBinaria(int *v, int n, int elem) {
    int inicio, meio, final;
    inicio = 0;
    final = n-1;

    while (inicio <= final) {
        meio = (inicio + final) / 2;

        if (elem < v[meio])
            final = meio-1;
        else if(elem > v[meio])
            inicio = meio+1;
        else
            return meio;
    }

    return -1;
}

int main() {
    int n = 9;
    int v[] = {-8, -5, 1, 4, 14, 21, 23, 54, 67, 90};

    printf("54: %d\n", buscaBinaria(v, n, 54));
    printf("32: %d\n", buscaBinaria(v, n, 32));
}