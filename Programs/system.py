def pop(n):
    x = (1.0 - 5**0.5)/2
    for i in range(n):
        print x
        x = 1 - x**2
    return x
p = int(raw_input())
print pop(p)
