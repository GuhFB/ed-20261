#include <stdio.h>

int fatorial_recursivo(int n) {
    if (n <= 1) return 1;
    return n * fatorial_recursivo(n - 1);
}

int main() {
    int n = 5;
    int fat = 1;

    for (int i = 1; i <= n; i++) {
        fat = fat * i;
    }

    printf("Repeticao (O(n)): %d\n", fat);
    printf("Recursivo (O(n)): %d\n", fatorial_recursivo(n));
    return 0;
}