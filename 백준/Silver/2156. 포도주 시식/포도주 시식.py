list = [0, 0, 0]
d = [0, 0, 0]
n = int(input())
result = 0

for i in range(3, n+3):
    temp = int(input())
    list.append(temp)
    if temp != 0:
        now = max(d[i-1], d[i-2]+list[i], d[i-3]+list[i-1]+list[i])
        if result < now:
            result = now
        d.append(now)   
    else:
        d.append(result)

print(result)   