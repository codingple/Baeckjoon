import sys
import heapq

inf = 200001

if __name__ == '__main__':
    V, E = map(int,sys.stdin.readline().rstrip().split(' '))
    start = int(sys.stdin.readline().rstrip())
    # 시작점으로 부터 모든 노드의 최소거리
    dist = [inf for _ in range(V+1)]
    # 노드 간의 거리 표시
    board = [[] for _ in range(V+1)]
    dist[start] = 0
    # [idx: 출발노드, [도착노드, 가중치]]
    for _ in range(E):
        u, v, w = list(map(int,sys.stdin.readline().rstrip().split(' ')))
        board[u].append([v,w])

    pq = []
    # 가중치에 따른 priority queue
    heapq.heappush(pq,[0,start])
    while len(pq):
        crnt_w,crnt_node = heapq.heappop(pq)
        # 모든 상대 노드에 대하여
        for node, w in board[crnt_node]:
            nw_w = w + crnt_w
            # 현재 노드가 도착한 거리 < 현재 최소거리
            if nw_w < dist[node]:
                dist[node] = nw_w
                heapq.heappush(pq,[nw_w,node])

    for i in range(1,V+1):
        if dist[i] != inf:
            print(dist[i])
        else:
            print("INF")