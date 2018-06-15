import math
n = int(raw_input())
c = 1
fib = [0, 1, 1]
fi = (1.0 + 5.0**(0.5))/2.0
print fi
a = 1
while(c <= n):
    a = ((fi**c) + (fi**-c))/(5**(0.5))
    if(c > 2):
           fib.append(fib[c - 1] + fib[c - 2])
    print math.floor(a) - fib[c]
    c += 1
