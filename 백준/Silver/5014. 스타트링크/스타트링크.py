from collections import deque
f, s, g, u, d = map(int, input().split())

visited = [0]*(f+1)
visited[s] = 1
count = 1
queue = deque()
queue.append(s)

if s == g:
    print('0')
else:
    while 1:
        if len(queue) > 0:
            s = queue.popleft()
        else:
            count = f
        
        up, down = s+u, s-d
        
        if up == g or down == g:
            print(visited[s])
            break
        
        if up<=f and visited[up] == 0:
            queue.append(up)
            visited[up]=visited[s]+1
            count +=1
        if down>0 and visited[down] == 0:
            queue.append(down)
            visited[down]=visited[s]+1
            count +=1
        if count == f:
            print("use the stairs")
            break
    