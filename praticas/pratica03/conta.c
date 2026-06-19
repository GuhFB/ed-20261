#include <stdlib.h>
#include "conta.h"

struct conta_t {
    int numero;
    float saldo;
};

Conta* conta_criar(int numero, float saldo_inicial) {
    Conta* c = (Conta*) malloc(sizeof(Conta));
    c->numero = numero;
    c->saldo = saldo_inicial;
    return c;
}

void conta_depositar(Conta* c, float valor) {
    c->saldo += valor;
}

void conta_sacar(Conta* c, float valor) {
    c->saldo -= valor;
}

float conta_ver_saldo(Conta* c) {
    return c->saldo;
}

void conta_destruir(Conta* c) {
    free(c);
}