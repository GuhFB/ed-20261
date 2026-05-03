#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

int main() {
    int v[100], i, pos;
    clock_t t;

    for(i = 0; i < 100; i++) v[i] = rand() % 1000;
    int alvo = v[50]; // Peguei um valor que sabemos que existe

    t = clock();
    pos = linear_search(v, 100, alvo);
    t = clock() - t;
    printf("Busca Linear: posicao %d, tempo %f s\n", pos, ((double)t)/CLOCKS_PER_SEC);

    t = clock();
    int menor = quick_select(v, 0, 99, 0);
    t = clock() - t;
    printf("Menor elemento (Quick Select): %d, tempo %f s\n", menor, ((double)t)/CLOCKS_PER_SEC);

    return 0;
}