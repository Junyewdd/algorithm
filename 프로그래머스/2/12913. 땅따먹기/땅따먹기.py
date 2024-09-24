def solution(land):
    answer = 0
    for i in range(1, len(land)):
        for j in range(len(land[i-1])):
            max = 0
            for k in range(len(land[i-1])):
                if k == j: continue
                if max < land[i-1][k]: max = land[i-1][k]
            land[i][j]+=max
    max = 0
    last = len(land)
    for i in range(len(land[last - 1])):
        if max < land[last-1][i]:
            max = land[last-1][i]
    answer = max
            
            
        

    return answer