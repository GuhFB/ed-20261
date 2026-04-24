#include "ordenacao.h"

void bubble_sort(int *v, int n) {
    int i, j, aux;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

void selection_sort(int *v, int n) {
    int i, j, min, aux;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min]) min = j;
        }
        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
}

void quick_sort(int *v, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = v[fim];
        int i = inicio - 1, aux;
        for (int j = inicio; j < fim; j++) {
            if (v[j] <= pivo) {
                i++;
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
        aux = v[i+1];
        v[i+1] = v[fim];
        v[fim] = aux;
        int p = i + 1;
        quick_sort(v, inicio, p - 1);
        quick_sort(v, p + 1, fim);
    }
}