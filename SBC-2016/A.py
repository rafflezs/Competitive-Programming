valores = map(int, input().split())
valores = list(valores)

volta = True

while len(valores) > 0:
    maior = (max(valores))
    valores.remove(maior)
    if maior == sum(valores):
        volta = True
        break
    else:
        volta = False

if volta:
    print("S")
else:
    print("N")

## SOLVED