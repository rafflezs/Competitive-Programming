A,B,C,D = map(int, input().split())

res = -1

for i in range (A,max(A,B,C,D)+1):
    if i % A == 0:
        if i % B != 0:
            if C % i == 0:
                if D % i != 0:
                    res = i
                    break

print(res)

## SOLVED