/**
** Questão E - Abobora 2022
** Album da Copa - URI
**
** Descrição - Encontrar a quantidade restante
** de figs. pra completar o album.
** Problema da mochila.
**/

#include <stdio.h>
int leitura()
{
    int num;
    scanf("%d", &num);
    return num;
}
void zerar(int n, int *vet)
{
    int i;
    for (i = 0; i < n; i++)
    {
        vet[i] = 0;
    }
}
void ler_vetor(int m, int *vet)
{
    int i;
    for (i = 0; i < m; i++)
    {
        vet[leitura() - 1]++;
    }
}
int total(int n, int *vet)
{
    int i, c = 0;
    for (i = 0; i < n; i++)
    {
        if (!vet[i])
        {
            c++;
        }
    }
    return c;
}
void imprimi(int n, int *vet)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}
int main()
{
    int n, m;
    n = leitura();
    m = leitura();
    int vet[n];
    zerar(n, vet);
    ler_vetor(m, vet);
    printf("%d\n", total(n, vet));
}