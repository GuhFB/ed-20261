#include <stdio.h>

void decompor_saque(int saque) {
    int cedulas[] = {200, 100, 50, 20, 10, 5, 2};
    printf("Saque de R$%d:\n", saque);
    for(int i = 0; i < 7; i++) {
        int qtd = saque / cedulas[i];
        if(qtd > 0) {
            printf("  %d nota(s) de %d\n", qtd, cedulas[i]);
            saque %= cedulas[i];
        }
    }
}

int main() {
    decompor_saque(487); // Esperado: 2x200, 1x50, 1x20, 1x10, 1x5, 1x2
    decompor_saque(100); // Esperado: 1x100
    return 0;
}