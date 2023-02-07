from bisect import bisect
from itertools import accumulate


def fracKnapsack(item, peso, limite, n):
    """
    >>> fracKnapsack([60, 100, 120], [10, 20, 30], 50, 3)
    240.0
    """

    r = list(sorted(zip(item, peso), key=lambda x: x[0] / x[1], reverse=True))
    item, peso = [i[0] for i in r], [i[1] for i in r]
    acc = list(accumulate(peso))
    k = bisect(acc, limite)
    return (
        0
        if k == 0
        else sum(item[:k]) + (limite - acc[k - 1]) * (item[k]) / (peso[k])
        if k != n
        else sum(item[:k])
    )

item = [60, 100, 120]
peso =  [10, 20, 30]
limite = 50
print(fracKnapsack( item , peso, limite, len(item)))