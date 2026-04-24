#include "selecao.h"

int linear_search(int *v, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (v[i] == x) return i;
    }
    return -1;
}

int quick_select(int *v, int inicio, int fim, int k) {
    if (inicio == fim) return v[inicio];
    
    int pivo = v[fim];
    int i = inicio, aux;
    for (int j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
        }
    }
    aux = v[i];
    v[i] = v[fim];
    v[fim] = aux;

    if (i == k) return v[i];
    if (i > k) return quick_select(v, inicio, i - 1, k);
    return quick_select(v, i + 1, fim, k);
}