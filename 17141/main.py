import sys
import itertools
import copy

dir = [
    [0, 1], [0, -1], [1, 0], [-1, 0]
]
r = 0
c = 1

def still_have_zero(board):
    for row in board:
        if 0 in row:
            return True
    return False

def bfs(board, virus_coord):
    crnt_board = copy.deepcopy(board)
    q = []
    for virus in virus_coord:
        q.append([virus, 0])
        crnt_board[virus[r]][virus[c]] = 1

    result = 0

    while len(q):
        crnt = q.pop(0)
        crnt_coord = crnt[0]
        crnt_depth = crnt[1]
        result = crnt_depth

        for d in range(4):
            nw_coord = [ crnt_coord[r] + dir[d][r], crnt_coord[c] + dir[d][c]]
            if not crnt_board[nw_coord[r]][nw_coord[c]]:
                q.append([nw_coord,crnt_depth+1])
                crnt_board[nw_coord[r]][nw_coord[c]] = 1

    if still_have_zero(crnt_board):
        return -1
    return result


if __name__ == '__main__':
    N, M = map(lambda x : int(x), sys.stdin.readline().strip().split(' '))
    board = []
    virus_list = []
    answer = -1

    for i in range(N):
        row = list(map(lambda x : int(x), sys.stdin.readline().strip().split(' ')))
        for j in range(N):
            if row[j] == 2:
                virus_list.append([i+1, j+1])
                row[j] = 0
        board.append([1] + row + [1])
    padding = [[1] * (N+2)]
    board = padding + board + padding

    comb_virus = itertools.combinations(virus_list, M)

    for virus_coords in comb_virus:
        crnt_answer = bfs(board, virus_coords)
        if answer < 0 or (crnt_answer > 0 and crnt_answer < answer):
            answer = crnt_answer

    print(answer)
