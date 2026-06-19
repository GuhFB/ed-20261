#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} No;

struct pilha_t {
    No *topo;
    int quantidade;
};

Pilha* pilha_criar() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));

    p->topo = NULL;
    p->quantidade = 0;

    return p;
}

void pilha_empilhar(Pilha* p, int valor) {
    No *novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->proximo = p->topo;

    p->topo = novo;
    p->quantidade++;
}

void pilha_desempilhar(Pilha* p) {
    if (p->topo == NULL)
        return;

    No *aux = p->topo;

    p->topo = aux->proximo;

    free(aux);

    p->quantidade--;
}

int pilha_topo(Pilha* p) {
    if (p->topo == NULL)
        return -1;

    return p->topo->valor;
}

int pilha_esta_vazia(Pilha* p) {
    return p->quantidade == 0;
}

void pilha_exibir(Pilha* p) {
    No *aux = p->topo;

    while (aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->proximo;
    }
}

void pilha_destruir(Pilha* p) {
    while (p->topo != NULL) {
        pilha_desempilhar(p);
    }

    free(p);
}