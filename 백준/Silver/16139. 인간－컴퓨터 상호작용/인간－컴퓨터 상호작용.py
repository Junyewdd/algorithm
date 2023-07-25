string = input()
n = int(input())
for i in range(n):
    line = input()
    ch, a, b = line.split(' ')
    temp = string[(int(a)):(int(b)+1)]
    print(temp.count(ch))