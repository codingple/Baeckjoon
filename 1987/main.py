# passed with pypy3
import sys

dir = [
    [0,1],[0,-1],[1,0],[-1,0]
]
r = 0
c = 1

answer = 0

def in_range(i,j,R,C):
    return 0 <= i and i < R and 0 <= j and j < C

def dfs(board,coord,alpha,cnt):

    for d in range(4):
        nw_coord = [ coord[r] + dir[d][r], coord[c] + dir[d][c] ]
        if in_range(nw_coord[r], nw_coord[c], R, C) and \
                alpha[board[nw_coord[r]][nw_coord[c]]]:
                alpha[board[nw_coord[r]][nw_coord[c]]] = 0
                dfs(board,nw_coord,alpha,cnt+1)
                alpha[board[nw_coord[r]][nw_coord[c]]] = 1

    global answer
    answer = max(answer, cnt)

if __name__ == '__main__':
    R, C = map(lambda x : int(x), sys.stdin.readline().strip().split(' '))
    board = []

    for i in range(R):
        board.append(list(map(lambda x : ord(x) - ord('A'), sys.stdin.readline().strip())))

    # R = 20
    # C = 20
    #
    # test = []
    # for k in range(40):
    #     ch = chr((k % 26) + ord('A'))
    #     if k < 20:
    #         test.append([])
    #     for i in range(min(k + 1, 20)):
    #         if len(test[i]) < 20:
    #             test[i].append( ord(ch) - ord('A') )

    crnt = [ 1 for i in range(26)]
    crnt[board[0][0]] = 0
    dfs(board, [0, 0], crnt, 1)
    print(answer)