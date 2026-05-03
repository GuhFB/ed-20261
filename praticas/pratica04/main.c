#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

int main() {
    int v[100], i;
    clock_t t;

    for(i = 0; i < 100; i++) v[i] = rand() % 1000;
    t = clock();
    bubble_sort(v, 100);
    t = clock() - t;
    printf("Tempo Bubble Sort: %f segundos\n", ((double)t)/CLOCKS_PER_SEC);

    for(i = 0; i < 100; i++) v[i] = rand() % 1000;
    t = clock();
    selection_sort(v, 100);
    t = clock() - t;
    printf("Tempo Selection Sort: %f segundos\n", ((double)t)/CLOCKS_PER_SEC);

    for(i = 0; i < 100; i++) v[i] = rand() % 1000;
    t = clock();
    quick_sort(v, 0, 99);
    t = clock() - t;
    printf("Tempo Quick Sort: %f segundos\n", ((double)t)/CLOCKS_PER_SEC);

    return 0;
}