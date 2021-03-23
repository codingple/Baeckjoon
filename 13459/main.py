import sys
import copy

dir = [
    [0,1],[0,-1],[1,0],[-1,0]
]
r = 0
c = 1

# 1. R과 B가 만날 때
# 2. R이 O로 들어갔을 때
# 3. B가 O로 들어갔을 때
def move(board,coord,d):
    stk = []
    dic = {}
    cnt = 0

    while board[coord[r]][coord[c]] != '#' and board[coord[r]][coord[c]] != 'O':
        if board[coord[r]][coord[c]] == 'R':
            stk.append('R')
        elif board[coord[r]][coord[c]] == 'B':
            stk.append('B')
        coord = [ coord[r]+dir[d][r], coord[c]+dir[d][c] ]
        cnt+=1

    if board[coord[r]][coord[c]] == 'O':
        return dic

    for i in range(cnt):
        coord = [ coord[r]-dir[d][r], coord[c]-dir[d][c] ]
        if len(stk):
            char = stk.pop()
            board[coord[r]][coord[c]] = char
            dic[char] = copy.deepcopy(coord)
        else:
            board[coord[r]][coord[c]] = '.'

    return dic


def bfs(board,R,B):
    q = [[board,R,B,0]]
    trace = [[R,B]]

    while len(q):
        crnt = q.pop(0)
        crnt_board = crnt[0]
        crnt_R = crnt[1]
        crnt_B = crnt[2]
        crnt_depth = crnt[3]

        if crnt_depth == 10:
            continue

        for d in range(4):
            nw_board = copy.deepcopy(crnt_board)
            dic = move(nw_board,crnt_B,d)

            if len(dic) == 0:
                continue

            elif len(dic) == 1:
                nw_B = dic['B']
                dic_r = move(nw_board, crnt_R, d)
                if not len(dic_r):
                    return 1
                else:
                    nw_R = dic_r['R']

            elif len(dic) == 2:
                nw_B = dic['B']
                nw_R = dic['R']
            if [nw_R, nw_B] not in trace:
                trace.append([nw_R, nw_B])
                q.append([nw_board,nw_R,nw_B,crnt_depth+1])

    return 0


if __name__ == '__main__':
    N, M = map(lambda x : int(x), sys.stdin.readline().strip().split(' '))
    board = []
    R = []
    B = []

    for i in range(N):
        row = list(sys.stdin.readline().strip())
        for j in range(M):
            if row[j] == 'R':
                R = [i, j]
            elif row[j] == 'B':
                B = [i, j]

        board.append(row)

    print(bfs(board,R,B))