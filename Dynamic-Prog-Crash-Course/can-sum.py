## Questão
## Dado um conjunto de números n e um valor alvo x, verifique
## se é possível atingir o número alvo a partir da soma dos
## elementos de n
##
## O retorno da função é booleano e indica se há ou não soma
## a partir do conjunto n.
##
## Os elementos podem ser usados repetidas vezes
## As entradas são NÃO-NEGATIVAS

def can_sum(target, num_set, memo = {}):
    if target in memo:
        return memo[target]
    
    if (target == 0):
        return True
    if target < 0:
        return False
    
    
    for i in num_set:
        resto = target - i
        if (can_sum(resto, num_set, memo)) == True:
            memo[resto] = True
            return True
    
    memo[target] = False
    return False

print(can_sum(3, {4,2})) ## False
print(can_sum(20, {10,5})) ## True
print(can_sum(300, {7,14})) ## False