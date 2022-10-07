## Questão
## Um viajante está preso em uma matriz 2D. Ele começa no canto superior-esquerdo [0][0]
## e para sair desse plano, ele deve chegar ao canto inferior-direito [m][n].
## Ele só pode se mover para baixo OU para esquerda.
##
## De quantas maneiras ele pode chegar ao destino em uma matriz 2D (m,n)?

def grid_travel(m,n, memo = {}):
    key = str(m) + ',' + str(n)
    if key in memo:
        return memo[key]
    if m == 0 or n == 0:
        return 0
    if m == 1 and n == 1:
        return 1

    memo[key] = grid_travel(m-1, n) + grid_travel(m, n-1)
    return memo[key]

print(grid_travel(0,0))
print(grid_travel(1,1))
print(grid_travel(1,2))
print(grid_travel(2,1))
print(grid_travel(2,3))
print(grid_travel(3,2))
print(grid_travel(3,3))
print(grid_travel(5,6))
print(grid_travel(18,18))
print(grid_travel(100,100))


# teste = {
#     1: {
#         1: 1
#     },
#     1: {
#         2: 1
#     },
#     2: {
#         1: 1
#     },
#     2: {
#         2: 2
#     },
# }

# if 1 not in teste[1]:
#     teste[1][3] = 2
#     print(teste[1][3])