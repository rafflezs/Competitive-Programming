## Questão
## Dado um conjunto de números n e um valor alvo x, verifique
## se é possível atingir o número alvo a partir da soma dos
## elementos de n
##
## O retorno da função UMA combinações que alcança
## o valor alvo x. Caso não haja combinações, retornar None.
##
## Os elementos podem ser usados repetidas vezes
## As entradas são NÃO-NEGATIVAS

def how_sum(targetSum, nums, memo = None): 

    if memo is None:
        memo = {}
        
    if targetSum in memo: return memo[targetSum]
    if targetSum < 0: return None
    if targetSum == 0: return []

    for num in nums:
        remainder = targetSum - num
        remainderResult = how_sum(remainder, nums , memo ) #pass memo as well
        
        if remainderResult is not None:
            remainderResult.append(num)
            memo[targetSum] = remainderResult
            return memo[targetSum]
        
    memo[targetSum] = None
    return None

print(how_sum(3, {1,2})) ## [1,1,1]
print(how_sum(3, {4,2})) ## None
print(how_sum(20, {10,5})) ## [10, 10]
print(how_sum(300, {7,14})) ## None