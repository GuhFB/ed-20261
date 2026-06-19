#include <stdio.h>
#include "fila.h"

int main() {
    Fila *f = fila_criar();

    fila_enfileirar(f, 10);
    fila_enfileirar(f, 20);
    fila_enfileirar(f, 30);
    fila_enfileirar(f, 40);

    printf("Fila: ");
    fila_exibir(f);

    printf("Inicio: %d\n", fila_inicio(f));

    printf("Desenfileirado: %d\n", fila_desenfileirar(f));

    printf("Fila: ");
    fila_exibir(f);

    printf("Inicio: %d\n", fila_inicio(f));

    fila_destruir(f);

    return 0;
}