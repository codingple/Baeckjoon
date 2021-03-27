import sys
from collections import deque


dir = [
    [0,1],[0,-1],[1,0],[-1,0]
]
r = 0
c = 1
N = 0
M = 0

def in_range(coord):
    return 0 <= coord[r] and coord[r] < N and 0 <= coord[c] and coord[c] < M

def bfs(board,coord,check):
    q = deque()
    q.append([coord, 1, 0])
    check[coord[r]][coord[c]][0] = 0
    check[coord[r]][coord[c]][1] = 0

    while len(q):
        crnt_coord, crnt_cnt, crnt_broke = q.popleft()

        if crnt_coord[r] == N - 1 and crnt_coord[c] == M - 1:
            return crnt_cnt

        for d in range(4):
            nw_coord = [ crnt_coord[r]+dir[d][r], crnt_coord[c]+dir[d][c] ]

            if in_range(nw_coord) and check[nw_coord[r]][nw_coord[c]][crnt_broke]:
                if board[nw_coord[r]][nw_coord[c]] == 0:
                    check[nw_coord[r]][nw_coord[c]][crnt_broke] = 0
                    q.append([nw_coord,crnt_cnt+1,crnt_broke])

                if board[nw_coord[r]][nw_coord[c]] == 1 and crnt_broke != 1:
                    nw_broke = 1
                    check[nw_coord[r]][nw_coord[c]][nw_broke] = 0
                    q.append([nw_coord,crnt_cnt+1,nw_broke])

    return -1


if __name__ == "__main__":
    Input = sys.stdin.readline().rstrip()
    N, M = map(int, Input.split(' '))

    board = []
    check = [[[1,1] for _ in range(M)] for _ in range(N)]
    for _ in range(N):
        board.append(list(map(int, sys.stdin.readline().rstrip())))

    print(bfs(board,[0,0],check))