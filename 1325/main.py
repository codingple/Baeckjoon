import sys
from collections import deque
answer = []
max_num = 0

def bfs(board,start):
    res = 1
    q = deque()
    q.append(start)
    check = [1] * (N + 1)
    check[start] = 0

    while len(q):
        node = q.popleft()

        for i in board[node]:
            if check[i]:
                check[i] = 0
                res += 1
                q.append(i)

    return res


N, M = map(int, sys.stdin.readline().rstrip().split(' '))
board = [[] for _ in range(N+1)]

for _ in range(M):
    j, i = map(int, sys.stdin.readline().rstrip().split(' '))
    board[i].append(j)

for i in range(len(board)):
    if len(board[i]):
        start = i
        res = bfs(board,start)
        if res > max_num:
            max_num = res
            answer = [start]
        elif res == max_num:
            answer.append(start)

for i in answer:
    print(str(i) + ' ', end='')