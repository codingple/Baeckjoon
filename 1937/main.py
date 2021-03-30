import sys
sys.setrecursionlimit(10000000)
answer = 1

d_x = [0, 0, 1, -1]
d_y = [1, -1, 0, 0]
N = 0

def in_range(i,j):
    return 0<=i and i <N and 0<=j and j<N

def dfs(board,memo,i,j):
    crnt = board[i][j]
    crnt_sum = [1,1,1,1]

    for d in range(4):
        nw_i = i + d_x[d]
        nw_j = j + d_y[d]
        if in_range(nw_i,nw_j) and board[nw_i][nw_j] > crnt:
            if memo[nw_i][nw_j] != -1:
                crnt_sum[d] += memo[nw_i][nw_j]
            else:
                crnt_sum[d] += dfs(board,memo,nw_i,nw_j)

    max_num = max(crnt_sum)
    memo[i][j] = max_num
    return max_num

if __name__ == '__main__':
    N = int(sys.stdin.readline().rstrip())
    board = []
    memo = [[-1 for _ in range(N)] for __ in range(N)]

    # test = []
    # cnt = 1
    # for i in range(1,501):
    #     test.append([])
    #     for j in range(1,501):
    #         test[i-1].append(cnt)
    #         cnt+=1
    for _ in range(N):
        row = list(map(int, sys.stdin.readline().rstrip().split(' ')))
        board.append(row)

    for i in range(N):
        for j in range(N):
            answer = max(answer,dfs(board,memo,i,j))

    print(answer)