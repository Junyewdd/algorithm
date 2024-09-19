n = int(input())
d = [1000000]*(n+1)

d[1] = 0

for i in range(1, n+1):
    if i*3<=n:
        d[3*i] = min(d[i]+1, d[3*i])
    if i*2<=n:
        d[2*i] = min(d[i]+1, d[2*i])
    if i+1<=n:
        d[i+1] = min(d[i]+1, d[i+1])
print(d[n])