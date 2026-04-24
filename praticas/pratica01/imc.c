#include <stdio.h>

void testar_imc(float peso, float altura, const char* esperado) {
    float imc = peso / (altura * altura);
    printf("Teste: Peso %.1f, Altura %.2f -> IMC %.1f | ", peso, altura, imc);
    
    if (imc < 18.5) printf("Esperado: Abaixo do peso | %s\n", esperado);
    else if (imc < 25.0) printf("Esperado: Peso normal | %s\n", esperado);
    else if (imc < 30.0) printf("Esperado: Sobrepeso | %s\n", esperado);
    else printf("Esperado: Obesidade | %s\n", esperado);
}

int main() {
    testar_imc(50.0, 1.70, "Abaixo do peso");
    testar_imc(70.0, 1.75, "Peso normal");
    testar_imc(85.0, 1.75, "Sobrepeso");
    testar_imc(100.0, 1.70, "Obesidade");
    return 0;
}