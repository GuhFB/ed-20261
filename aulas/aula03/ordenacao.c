#include <stdio.h>
#include "ordernacao.h"

void troca (int *a, int *b) 
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble_sort (int v[], int n) //O(n²)
{
    for (int i = 0; i < n-1; i++) // n-1 vezes
    {
        for (int j = i+1; j < n; j++) // n-1 
        {
            if (v[i] > v[j]) 
            {
                troca (&v[i], &v[j]);
            }
        }
    }
}

void imprimir_vetor(int v[], int n)
{
    printf("[");
    for (int i=0; i < n-1; i++)
    {
        printf("%i, ", v[i]);
    }
    printf("%i]\n", v[n-1]);
}