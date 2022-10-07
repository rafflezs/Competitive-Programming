## Memorando
## hash map, tal qual (key) == n e (val) == return

def fib(n, memo = {}):
    if (n in memo):
        return memo.get(n)
    if (n <= 2):
        return 1
    memo[n] = fib(n-1) + fib(n-2)
    return memo.get(n)

print(fib(10))

# teste = {
#     1: 1,
#     2: 1,
#     3: 2,
#     4: 3,
#     5: 5,
#     6: 8,
#     7: 13
# }

# if 8 not in teste:
#     teste[8] = teste.get(8-1) + teste.get(8-2)
#     print(teste.get(8))