#행렬 값 저장
n, m = map(int, input().split())
mat1 = []
for _ in range(n):
    mat1.append(list(map(int, input().split())))

m, k = map(int, input().split())
mat2=[]
for _ in range(m):
    mat2.append(list(map(int, input().split())))
    
# 행렬 곱셈
result = [[0 for _ in range(k)] for _ in range(n)]
for i in range(n):
    for j in range(k):
        for l in range(m):
            result[i][j] += mat1[i][l] * mat2[l][j]

for i in result:
    for j in i:
        print(j, end = ' ')
    print()