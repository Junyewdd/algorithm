n = int(input())
for i in range(n):
    if i % 2 != 0:
        print(" ", end="")
    for j in range(n):
        if j == n-1:
            print("*")
        else:    
            print("*", end=' ')