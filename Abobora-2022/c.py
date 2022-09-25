## Questão C - Abobora 2022
## Problema da Piscina - Belo
##
## Descricao - encontrar a quantidade T de azulejos de Q area
## para cobrir todos os lados da piscina, e mostrar a área D de
## azulejos desperciçados 
##

from math import ceil

q,c,l,p = [float(x) for x in input().split()]

T = ceil(c/q)*ceil(l/q) + 2*ceil(c/q)*ceil(p/q) + 2*ceil(l/q)*ceil(p/q)
D = T - (c*l+2*c*p+2*l*p)/(q**2)

print (T,round(D,2))
