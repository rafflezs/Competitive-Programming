/**
** Questão A - Abobora 2022
** Sei la o nome - Douglas
**
** Descrição - Problema do boi.
** Basicamente encontrar o menor elemento
** de um vetor e trocar com a posição 0.
**/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int ler()
{
    int num;
    scanf("%d", &num);
    return num;
}
void vetor(int n, int *vet)
{
    int i;
    for (i = 0; i < n; i++)
    {
        vet[i] = ler();
    }
}
void escrever(int n, int *vet)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}
void troca(int *x, int *y)
{
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}
void ordena(int n, int *vet)
{
    int i, j;
    int menor;
    for (i = 0; i < n - 1; i++)
    {
        menor = i;
        for (j = i; j < n; j++)
        {
            if (vet[j] < vet[menor])
            {
                menor = j;
            }
        }
        troca(&vet[menor], &vet[i]);
    }
}
int main()
{
    int n = ler();
    int vet[n];
    vetor(n, vet);
    ordena(n, vet);
    escrever(n, vet);
}