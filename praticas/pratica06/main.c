#include <stdio.h>
#include "lista_linear.h"

int main() {
    Lista *l = lista_criar();

    lista_inserir(l, 10);
    lista_inserir(l, 20);
    lista_inserir(l, 30);
    lista_inserir(l, 40);

    printf("Lista: ");
    lista_exibir(l);

    printf("Busca do valor 30: %d\n", lista_buscar(l, 30));

    lista_remover(l, 20);

    printf("Lista apos remover 20: ");
    lista_exibir(l);

    printf("Lista vazia: %d\n", lista_esta_vazia(l));

    lista_destruir(l);

    return 0;
}