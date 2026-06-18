#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no_t {
    struct no_t *anterior;
    int valor;
    struct no_t *proximo;
} No;

struct lista_t {
    No *inicio;
    No *final;
    int quantidade;
};

Lista* lista_criar() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->inicio = NULL;
    l->final = NULL;
    l->quantidade = 0;
    return l;
}

void lista_inserir(Lista* l, int valor) {
    No *novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->anterior = l->final;
    novo->proximo = NULL;

    if (l->final != NULL)
        l->final->proximo = novo;
    else
        l->inicio = novo;

    l->final = novo;
    l->quantidade++;
}

void lista_remover(Lista* l, int valor) {
    No *p = l->inicio;

    while (p != NULL) {
        if (p->valor == valor) {
            if (p->anterior != NULL)
                p->anterior->proximo = p->proximo;
            else
                l->inicio = p->proximo;

            if (p->proximo != NULL)
                p->proximo->anterior = p->anterior;
            else
                l->final = p->anterior;

            free(p);
            l->quantidade--;
            return;
        }

        p = p->proximo;
    }
}

int lista_buscar(Lista* l, int valor) {
    No *p = l->inicio;
    int pos = 0;

    while (p != NULL) {
        if (p->valor == valor)
            return pos;

        p = p->proximo;
        pos++;
    }

    return -1;
}

void lista_exibir(Lista* l) {
    No *p = l->inicio;

    while (p != NULL) {
        printf("%d ", p->valor);
        p = p->proximo;
    }

    printf("\n");
}

int lista_esta_vazia(Lista* l) {
    return l->quantidade == 0;
}

void lista_destruir(Lista* l) {
    No *p = l->inicio;

    while (p != NULL) {
        No *aux = p;
        p = p->proximo;
        free(aux);
    }

    free(l);
}