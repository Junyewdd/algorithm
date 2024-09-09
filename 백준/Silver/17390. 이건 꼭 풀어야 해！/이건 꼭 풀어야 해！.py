import sys
n, m = map(int,sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
arr.sort()

for i in range(1, len(arr)):
    arr[i] += arr[i-1]

for i in range(m):
    line = sys.stdin.readline()
    p, q = map(int,line.split())
    if p == 1:
        print(arr[q-1])
    else:
        print(arr[q-1]-arr[p-2])