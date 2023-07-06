n, m = map(int, input().split(' '))

matrix = []

for i in range(n):
    nums = input().split(' ')
    matrix.append(nums)
for i in range(n):
    nums = input().split(' ')
    for j in range(m):
        matrix[i][j] = int(matrix[i][j])+int(nums[j])
    
    for j in range(m):
        if j == m-1:
            print(matrix[i][j])
        else:
            print(matrix[i][j], end=' ')