vec = [1, 1]
n, k = map(int, input().split())
for i in range(n - 2):
    vec[0], vec[1] = vec[1], vec[0]
    vec[1] = vec[0] + k*vec[1]
print(vec[1])
