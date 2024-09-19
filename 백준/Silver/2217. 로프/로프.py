n = int(input())
list = []
min = 10000
for i in range(n):
    list.append(int(input()))
list.sort()

result = 0
list_len = len(list)
for i in range(len(list)):
    if list[i]*(list_len - i) > result:
        result = list[i]*(list_len - i)
        
print(result)