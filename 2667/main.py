import sys

dir = [
    [0, 1], [0,-1], [1,0],[-1,0]
]
r = 0
c = 1

def bfs(board, coord):
    q = [coord]
    depth = 0

    while len(q):
        depth += 1
        crnt_coord = q.pop(0)
        board[coord[r]][coord[c]] = 0

        for d in range(4):
            nw_coord = [ crnt_coord[r] + dir[d][r], crnt_coord[c] +dir[d][c] ]
            if board[nw_coord[r]][nw_coord[c]]:
                board[nw_coord[r]][nw_coord[c]] = 0
                q.append(nw_coord)

    return depth

if __name__ == '__main__':
    N = int(sys.stdin.readline().strip())
    board = []
    for i in range(N):
        row = list(sys.stdin.readline().strip())
        nw_row = list(map(lambda x : int(x), row))
        board.append([0] + nw_row + [0])
    padding = [[0 for i in range(N+2)]]
    board = padding + board + padding

    answer = []
    for i in range(1,N+1):
        for j in range(1,N+1):
            if board[i][j]:
                answer.append(bfs(board,[i,j]))

    answer.sort()
    answer.insert(0,len(answer))

    for a in answer:
        print(a)