#include "tabela_hash.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

struct tabela_hash {
    No **tabela;
    int tamanho;
};

static int funcao_hash(TabelaHash *hash, int valor) {
    return abs(valor) % hash->tamanho;
}

TabelaHash *hash_criar(int tamanho) {
    TabelaHash *hash = malloc(sizeof(TabelaHash));

    if (!hash)
        return NULL;

    hash->tamanho = tamanho;
    hash->tabela = calloc(tamanho, sizeof(No *));

    return hash;
}

int hash_inserir(TabelaHash *hash, int valor) {
    int indice = funcao_hash(hash, valor);

    No *novo = malloc(sizeof(No));

    if (!novo)
        return 0;

    novo->valor = valor;
    novo->proximo = hash->tabela[indice];

    hash->tabela[indice] = novo;

    return 1;
}

int hash_buscar(TabelaHash *hash, int valor) {
    int indice = funcao_hash(hash, valor);

    No *aux = hash->tabela[indice];

    while (aux != NULL) {
        if (aux->valor == valor)
            return 1;

        aux = aux->proximo;
    }

    return 0;
}

int hash_remover(TabelaHash *hash, int valor) {
    int indice = funcao_hash(hash, valor);

    No *aux = hash->tabela[indice];
    No *anterior = NULL;

    while (aux != NULL) {

        if (aux->valor == valor) {

            if (anterior == NULL)
                hash->tabela[indice] = aux->proximo;
            else
                anterior->proximo = aux->proximo;

            free(aux);
            return 1;
        }

        anterior = aux;
        aux = aux->proximo;
    }

    return 0;
}

void hash_exibir(TabelaHash *hash) {

    for (int i = 0; i < hash->tamanho; i++) {

        printf("[%d] -> ", i);

        No *aux = hash->tabela[i];

        while (aux != NULL) {
            printf("%d -> ", aux->valor);
            aux = aux->proximo;
        }

        printf("NULL\n");
    }
}

int hash_esta_vazia(TabelaHash *hash) {

    for (int i = 0; i < hash->tamanho; i++) {
        if (hash->tabela[i] != NULL)
            return 0;
    }

    return 1;
}

void hash_destruir(TabelaHash *hash) {

    for (int i = 0; i < hash->tamanho; i++) {

        No *aux = hash->tabela[i];

        while (aux != NULL) {
            No *temp = aux;
            aux = aux->proximo;
            free(temp);
        }
    }

    free(hash->tabela);
    free(hash);
}