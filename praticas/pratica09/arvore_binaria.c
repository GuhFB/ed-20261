#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no_t {
    int valor;
    struct no_t *esquerda;
    struct no_t *direita;
} No;

struct arvore_t {
    No *raiz;
};

No *criar_no(int valor) {
    No *novo = (No *)malloc(sizeof(No));

    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

No *inserir(No *raiz, int valor) {
    if (raiz == NULL)
        return criar_no(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);

    return raiz;
}

void pre_ordem(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void em_ordem(No *raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->valor);
        em_ordem(raiz->direita);
    }
}

void pos_ordem(No *raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void destruir(No *raiz) {
    if (raiz != NULL) {
        destruir(raiz->esquerda);
        destruir(raiz->direita);
        free(raiz);
    }
}

Arvore *arvore_criar() {
    Arvore *a = (Arvore *)malloc(sizeof(Arvore));

    a->raiz = NULL;

    return a;
}

int arvore_esta_vazia(Arvore *a) {
    return a->raiz == NULL;
}

void arvore_inserir(Arvore *a, int valor) {
    a->raiz = inserir(a->raiz, valor);
}

void arvore_exibir_pre_ordem(Arvore *a) {
    pre_ordem(a->raiz);
    printf("\n");
}

void arvore_exibir_em_ordem(Arvore *a) {
    em_ordem(a->raiz);
    printf("\n");
}

void arvore_exibir_pos_ordem(Arvore *a) {
    pos_ordem(a->raiz);
    printf("\n");
}

void arvore_destruir(Arvore *a) {
    destruir(a->raiz);
    free(a);
}