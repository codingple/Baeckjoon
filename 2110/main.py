import sys

def bi_srch(i, j, board, n):
    if j - i == 1:
        if abs(n - board[i]) < abs(n - board[j]):
            return board[i]
        else:
            return board[j]

    mid = int((j - i) / 2) + i
    if board[mid] < n:
        return bi_srch(mid,j,board,n)
    else:
        return bi_srch(i, mid, board, n)


if __name__ == '__main__':
    N, C = list(map(int, sys.stdin.readline().rstrip().split(' ')))
    board = []
    for _ in range(N):
        k = int(sys.stdin.readline().rstrip())
        board.append(k)
    board.sort()

    C -= 2
    home = [board[0], board[-1]]
    K = int((board[-1] - board[0]) / (C + 1))

    for i in range(1, C+1):
        n = board[0] + (K * i)
        home.append(bi_srch(0, len(board)-1, board, n))

    max_num = 1000000000
    home.sort()
    for i in range(len(home) - 1):
        max_num = min(home[i+1] - home[i], max_num)

    print(max_num)