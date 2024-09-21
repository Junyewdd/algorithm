size = int(input())
array = []
d=[[0 for _ in range(size)] for _ in range(size)]

for i in range(size):
    line = list(map(int, input().split()))
    array.append(line)
d[0][0]=1

for i in range(size):
    for j in range(size):
        if array[i][j]==0 or d[i][j]==0:
            continue
        move = array[i][j]
        
        if j+move<size:
            d[i][j+move]+=d[i][j]
        if i+move< size:
            d[i+move][j]+=d[i][j]
print(d[size-1][size-1])