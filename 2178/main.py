import sys
import copy

dir = [
    [0,1],[0,-1],[1,0],[-1,0]
]
r = 0
c = 1

def bfs(board, coord, dest):
    q = [[coord, 1]]

    while len(q):
        crnt = q.pop(0)
        crnt_coord = crnt[0]
        crnt_depth = crnt[1]
        board[crnt_coord[r]][crnt_coord[c]] = 0

        if crnt_coord[r] == dest[r] and crnt_coord[c] == dest[c]:
            return crnt_depth

        for d in range(4):
            nw_coord = [crnt_coord[r] + dir[d][r],
                        crnt_coord[c] + dir[d][c]]
            if board[nw_coord[r]][nw_coord[c]]:
                board[nw_coord[r]][nw_coord[c]] = 0
                q.append([nw_coord, crnt_depth+1])

    return -1


if __name__ == '__main__':
    answer = 0
    NM = sys.stdin.readline().split(' ')
    N = int(NM[0])
    M = int(NM[1])
    board = []
    for i in range(N):
        row = list(sys.stdin.readline().strip())
        nw_row = list(map(lambda x: int(x), row))
        nw_row = [0] + nw_row + [0]
        board.append(nw_row)

    padding = [0 for i in range(M+2)]
    board.insert(0,padding)
    board.append(padding)
    answer = bfs(board,[1,1],[N,M])

    print(answer)