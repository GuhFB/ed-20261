#include <stdio.h>

int main() {
    int vetor[100];
    int busca = 42;
    int achou = -1;

    for (int i = 0; i < 100; i++) {
        vetor[i] = i;
    }

    for (int i = 0; i < 100; i++) {
        if (vetor[i] == busca) {
            achou = i;
            break;
        }
    }

    printf("Complexidade - Melhor: O(1), Pior: O(n)\n");
    printf("Posicao: %d\n", achou);
    return 0;
}