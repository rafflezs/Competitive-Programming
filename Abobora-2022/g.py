## Questão G - Abobora 2022
## Academia do Marlovsky - Belo
##
## Descricao - Problema Combinatorial cujo fundamento
## é encontrar a combinação de exercicios que o Marlus pode
## fazer com N equipamentos, P exercicios sendo que cada exercicio
## deve ser feito em equipamentos com diferença minima de R
##

def comb(n,p):
    p = min(p,n-p)
    if p < 0: return 0
    if p == 0: return 1
    res = n
    for i in range(1,p):
        res = res*(n-i)//(i+1)
    return res

def comb_mod(n,p,m):
    p = min(p,n-p)
    if p < 0: return 0
    if p == 0: return 1
    res = n % m
    for i in range(1,p):
        res = (res*(n-i)//(i+1))% m
    return res

def kaplansky(n,p,r=1):
    return comb(n-(p-1)*r,p)

def kaplansky_mod(n,p,r,m):
    return comb_mod(n-(p-1)*r,p,m)

n,p,r = [int(x) for x in input().split()]

print (kaplansky_mod(n,p,r-1,100000007))