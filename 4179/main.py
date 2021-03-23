import sys

dir = [
    [0,1],[0,-1],[1,0],[-1,0]
]
r = 0
c = 1

def goal(coord, R, C):
    return coord[r] == R or coord[r] == 1 or coord[c] == C or coord[c] == 1

def move_fire(board,all_fire):
    fires = []
    for F in all_fire:
        for d in range(4):
            nw_coord = [ F[r]+dir[d][r], F[c]+dir[d][c] ]
            if board[nw_coord[r]][nw_coord[c]] != '#' and board[nw_coord[r]][nw_coord[c]] != 'F':
                board[nw_coord[r]][nw_coord[c]] = 'F'
                fires.append(nw_coord)
    return fires


def bfs(board, J, F, R, C):
    answer = "IMPOSSIBLE"
    q = [[J,0]]

    while len(q):
        F = move_fire(board, F)
        N = len(q)
        for i in range(N):
            crnt = q.pop(0)
            crnt_j = crnt[0]
            crnt_depth = crnt[1]

            if goal(crnt_j, R, C):
                return crnt_depth+1

            for d in range(4):
                nw_coord = [ crnt_j[r]+dir[d][r], crnt_j[c]+dir[d][c] ]
                if board[nw_coord[r]][nw_coord[c]] == '.':
                    board[nw_coord[r]][nw_coord[c]] = 'J'
                    q.append([nw_coord,crnt_depth+1])

    return answer

if __name__ == '__main__':
    R, C = map(lambda x :int(x), sys.stdin.readline().strip().split(' '))
    board = []
    J = []
    F = []

    for i in range(R):
        row = sys.stdin.readline().strip()
        for j in range(C):
            if row[j] == 'J':
                J = [i+1, j+1]
            elif row[j] == 'F':
                F.append([i+1, j+1])
        board.append(['#'] + list(row) + ['#'])
    padding = [['#'] * (C+2)]
    board = padding + board + padding
    print(bfs(board, J, F, R, C))