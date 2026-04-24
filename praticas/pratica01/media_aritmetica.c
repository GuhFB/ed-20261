#include <stdio.h>

float calcular_media(int n, float v[]) {
    float soma = 0;
    for(int i = 0; i < n; i++) soma += v[i];
    return soma / n;
}

int main() {
    float v1[] = {10.0, 20.0, 30.0};
    printf("Media de 3 numeros: %.2f (Esperado: 20.00)\n", calcular_media(3, v1));
    return 0;
}