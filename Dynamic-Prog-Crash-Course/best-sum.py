## Questão
## Dado um conjunto de números n e um valor alvo x, verifique
## a menor soma possível para o número alvo a partir dos
## elementos de n
##
## O retorno da função A MENOR combinações que alcança
## o valor alvo x. Caso não haja combinações, retornar None.
##
## Se houver empate, retornar qualquer um dos conjuntos
##
## Os elementos podem ser usados repetidas vezes
## As entradas são NÃO-NEGATIVAS

def best_sum(targetsum, numbers, memo):
    if memo is None: memo = {}
    if targetsum in memo: return memo[targetsum]
    if targetsum == 0: return []
    if targetsum < 0: return None

    shortest_combination = None

    for num in numbers:
        remainder = targetsum - num
        remainder_result = best_sum(remainder, numbers, memo)
        if remainder_result != None:
            combination = [*remainder_result, num]
            if shortest_combination == None or len(combination) < len(shortest_combination):
                shortest_combination = combination
    memo[targetsum] = shortest_combination
    return memo[targetsum]

print(best_sum(3, [1,2], None)) ## [2,1]
print(best_sum(3, [4,2, 3, 1], None)) ## [3]
print(best_sum(21, [10,5, 6], None)) ## [10, 5, 6]
print(best_sum(300, [7,14], None)) ## None