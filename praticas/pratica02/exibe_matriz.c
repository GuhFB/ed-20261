#include <stdio.h>

int main() {
    int matriz[10][10];
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            matriz[i][j] = i + j;
        }
    }

    printf("Dois lacos (O(n^2)):\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", matriz[i][j]);
        }
    }

    printf("\n\nUm laco (O(n^2)):\n");
    for (i = 0; i < 100; i++) {
        printf("%d ", matriz[i / 10][i % 10]);
    }

    return 0;
}