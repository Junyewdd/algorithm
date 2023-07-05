g = [[-1]]
sum = [[-1]]
n = int(input())

for i in range(n):
    line = input()
    list = line.split(' ')
    for j in range(len(list)):
        list[j] = int(list[j])
    list1 = list[:]
    g.append(list)
    sum.append(list1)
    
for i in range(1, n):
    for j in range(len(g[i])):
        if sum[i+1][j]<g[i+1][j] + sum[i][j]:
            sum[i+1][j] = g[i+1][j] + sum[i][j]
        if sum[i+1][j+1]<g[i+1][j+1] + sum[i][j]:
            sum[i+1][j+1] = g[i+1][j+1] + sum[i][j]
            
max = 0
for i in range(len(sum[n])):
    if sum[n][i]>max:
        max = sum[n][i]  
print(max)