def conj_collatz(n, k, memo = {}):
    print(n)
    if n == 1:
        return 4
    if n % 2 == 0:
        conj_collatz(n/2,k,memo)
    else:
        conj_collatz(n*3+1,k,memo)

n,k = input().split()
n = int(n)
k = int(k)

conj_collatz(n,k)