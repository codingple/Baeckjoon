import sys

inf = 5000001

if __name__ == '__main__':
    N, M = map(int,sys.stdin.readline().rstrip().split(' '))
    board = [[] for _ in range(N+1)]
    dist = [inf for _ in range(N+1)]
    dist[1] = 0

    for _ in range(M):
        s, d, w = list(map(int,sys.stdin.readline().rstrip().split(' ')))
        board[s].append([d, w])

    for i in range(1,N+1):
        for cur in range(1,N+1):
            if dist[cur] == inf:
                continue
            for to, weight in board[cur]:
                if dist[cur] + weight < dist[to]:
                    dist[to] = dist[cur] + weight
                    if i == N:
                        print(-1)
                        quit()

    for i in range(2,N+1):
        if dist[i] == inf:
            print(-1)
        else:
            print(dist[i])