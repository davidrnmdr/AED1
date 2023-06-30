#include <stdio.h>

int main() {
    int X[10];

    // le o array X
    for (int i = 0; i < 10; i++) {
        scanf("%d", &X[i]);
    }

    // faz as substituicoes
    for (int i = 0; i < 10; i++) {
        if (X[i] <= 0) {
            X[i] = 1;
        }
    }

    // imprime
    for (int i = 0; i < 10; i++) {
        printf("X[%d] = %d\n", i, X[i]);
    }

    return 0;
}

