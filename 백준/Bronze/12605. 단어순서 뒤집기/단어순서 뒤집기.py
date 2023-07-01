n = int(input())

for i in range(n):
    list = input().split()
    print(f"Case #{i+1}: ", end='')
    newList = []
    for j in range(len(list)):
        newList.append(list[len(list)-j-1])
    for j in range(len(list)):
        if(j == len(list)-1):
            print(newList[j], end='')
        else:
            print(newList[j], end=' ')
    print("")