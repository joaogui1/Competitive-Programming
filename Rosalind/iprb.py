import math as mt

def binomial(a, b):
    if a < b:
        return 0
    x = mt.factorial(a)
    y = mt.factorial(b)
    z = mt.factorial(a - b)
    ret = x//(y*z)
    return ret

k, m, n = map(int, input().split())

ans = binomial(k, 2) + k*m + k*n + 0.75*binomial(m, 2) + 0.5*m*n
ans = ans/binomial(n + m + k, 2)
print(ans)
