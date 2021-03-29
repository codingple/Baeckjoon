import sys
sys.setrecursionlimit(100000)

dir = [
    [0,1],[0,-1],[1,0],[-1,0]
]
r = 0
c = 1

answer = 1
cnt = 0

def init_check(check, N):
    for i in range(N):
        for j in range(N):
            check[i][j] = 1

def in_range(i,j,N):
    return 0<=i and i<N and 0<=j and j<N

def dfs(board,coord,height,check,N):
    global cnt

    for d in range(4):
        nw_coord = [ coord[r] + dir[d][r], coord[c] + dir[d][c] ]
        if in_range(nw_coord[r],nw_coord[c],N) and\
                check[nw_coord[r]][nw_coord[c]] and\
            board[nw_coord[r]][nw_coord[c]] > height:
            check[nw_coord[r]][nw_coord[c]] = 0
            dfs(board,nw_coord,height,check,N)



if __name__ == '__main__':
    N = int(sys.stdin.readline().rstrip())
    check_num = [0 for _ in range(101)]
    board = []
    max_num = 0
    for _ in range(N):
        row = list(map(int,sys.stdin.readline().rstrip().split(' ')))
        for i in row:
            max_num = max(max_num, i)
        board.append(row)

    check = [[1 for _ in range(N)] for __ in range(N)]

    for height in range(max_num):
        init_check(check,N)
        cnt = 0
        for i in range(N):
            for j in range(N):
                if check[i][j] and board[i][j] > height:
                    check[i][j] = 0
                    cnt += 1
                    dfs(board,[i,j],height,check,N)
        answer = max(answer,cnt)

    print(answer)