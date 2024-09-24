def solution(N, stages):
    answer = []
    num = len(stages)
    persons = [0 for _ in range(N+2)]
    info = [[0, 0] for _ in range(N+1)]
    for i in range(len(stages)):
        persons[stages[i]]+=1
    
    for i in range(1, N+1):
        info[i][0] = i
        if num == 0:
            info[i][1] = 0
        else:
            info[i][1] = persons[i]/num
        num-=persons[i]
    info = sorted(info, key = lambda info: -info[1])
    for e in info:
        if e[0]==0:continue
        answer.append(e[0])    
    
    return answer