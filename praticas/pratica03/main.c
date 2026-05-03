#include <stdio.h>
#include "conta.h"

int main() {
    Conta* minha_conta = conta_criar(123, 500.0);
    
    conta_depositar(minha_conta, 200.0);
    conta_sacar(minha_conta, 100.0);
    
    printf("Saldo final: %.2f\n", conta_ver_saldo(minha_conta));
    
    conta_destruir(minha_conta);
    return 0;
}