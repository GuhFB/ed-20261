#include <stdio.h>

long long calcular_potencia(int base, int exp) {
    long long res = 1;
    for(int i = 0; i < exp; i++) res *= base;
    return res;
}

int main() {
    printf("2^3 = %lld (Esperado: 8)\n", calcular_potencia(2, 3));
    printf("5^2 = %lld (Esperado: 25)\n", calcular_potencia(5, 2));
    printf("10^0 = %lld (Esperado: 1)\n", calcular_potencia(10, 0));
    return 0;
}