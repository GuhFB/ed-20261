#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha *p = pilha_criar();

    pilha_empilhar(p, 10);
    pilha_empilhar(p, 20);
    pilha_empilhar(p, 30);

    printf("Pilha:\n");
    pilha_exibir(p);

    printf("\nTopo: %d\n", pilha_topo(p));

    pilha_desempilhar(p);

    printf("\nDepois de desempilhar:\n");
    pilha_exibir(p);

    printf("\nTopo: %d\n", pilha_topo(p));

    printf("\nPilha vazia: %d\n", pilha_esta_vazia(p));

    pilha_destruir(p);

    return 0;
}