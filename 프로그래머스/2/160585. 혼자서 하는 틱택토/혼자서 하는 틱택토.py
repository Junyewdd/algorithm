def won(board, t):
    # 가로
    for row in board:
        if row == [t, t, t]:
            return True
    
    # 세로
    for col in range(3):
        if [board[row][col] for row in range(3)] == [t, t, t]:
            return True
    
    #대각선
    if [board[0][0], board[1][1], board[2][2]] == [t, t, t]:
        return True
    if [board[0][2], board[1][1], board[2][0]] == [t, t, t]:
        return True
    return False
    
    
    
def solution(board):
    board = [list(row) for row in board]
    count_o = 0
    count_x = 0
    for row in board:
        for col in row:
            if col == 'O':
                count_o += 1
            elif col == 'X':
                count_x += 1
    
    print(won(board, 'O'))
    print(won(board, 'X'))
    print(count_o)
    print(count_x)  
    
    # 숫자 이상한 경우
    if count_o != count_x and count_o - count_x != 1:
        return 0
    
    # 둘 다 이긴 경우
    if won(board, 'O') and won(board, 'X'):
        return 0
    
    # o가 이겼을 때 o 개수가 1 많음
    if won(board, 'O') and count_o - count_x != 1:
        return 0
    
    # X가 이겼을 때 o 개수 == x 개수
    if won(board,'X') and count_o != count_x:
        return 0
    
      
    return 1
