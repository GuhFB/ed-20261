#include "tabela_hash.h"
#include <stdio.h>

int main() {

    TabelaHash *hash = hash_criar(7);

    printf("Tabela vazia? %s\n\n",
           hash_esta_vazia(hash) ? "Sim" : "Nao");

    hash_inserir(hash, 10);
    hash_inserir(hash, 20);
    hash_inserir(hash, 15);
    hash_inserir(hash, 7);
    hash_inserir(hash, 17);
    hash_inserir(hash, 24);

    printf("Tabela Hash:\n");
    hash_exibir(hash);

    printf("\nBuscar 15: %s\n",
           hash_buscar(hash, 15) ? "Encontrado" : "Nao encontrado");

    printf("Buscar 30: %s\n",
           hash_buscar(hash, 30) ? "Encontrado" : "Nao encontrado");

    printf("\nRemovendo 15...\n");
    hash_remover(hash, 15);

    printf("\nTabela apos remocao:\n");
    hash_exibir(hash);

    hash_destruir(hash);

    return 0;
}