import sys

dir = [
    lambda x : x+1,
    lambda x : x-1,
    lambda x : x*2,
]

def in_range(x):
    return 0 <= x and x <= 100000

if __name__ == '__main__':
    N, K = map(lambda x : int(x), sys.stdin.readline().strip().split(' '))
    board = [1 for i in range(100001)]
    board[K] = 2
    board[N] = 0

    q = [[N, 0]]

    while len(q):
        crnt = q.pop(0)
        crnt_pos = crnt[0]
        crnt_depth = crnt[1]

        if crnt_pos == K:
            print(crnt_depth)
            break

        for d in range(3):
            nw_pos = dir[d](crnt_pos)
            if in_range(nw_pos) and board[nw_pos]:
                board[nw_pos] = 0
                q.append([nw_pos, crnt_depth+1])