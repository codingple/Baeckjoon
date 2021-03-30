import sys
from collections import deque
import copy

N = 0
K = 0
stat = []
wannabe =[]
already = [None,None]

def push_already(stat,node,depth):
    if depth < N:
        if node[stat[depth]] == None:
            node[stat[depth]] = [None,None]
        push_already(stat,node[stat[depth]],depth+1)

def check_already(stat,node,depth):
    if depth < N:
        if node[stat[depth]] == None:
            return False
        else:
            return check_already(stat,node[stat[depth]],depth+1)
    return True

def check_same(stat):
    for i in range(N):
        if stat[i] != wannabe[i]:
            return False
    return True

def bfs():
    q = deque()
    global stat
    q.append([copy.deepcopy(stat), 0])

    while len(q):
        crnt = q.popleft()
        crnt_stat = crnt[0]
        crnt_cnt = crnt[1]

        if check_same(crnt_stat):
            return crnt_cnt

        head = 0
        rear = K-1

        while rear < N:
            for j in range(head,rear+1):
                nw_stat = copy.deepcopy(crnt_stat)
                for i in range(head,rear+1):
                    if i != j:
                        nw_stat[i] = (nw_stat[i] + 1) % 2
                if not check_already(nw_stat,already,0):
                    q.append([nw_stat,crnt_cnt+1])
                    push_already(nw_stat,already,0)
            head += 1
            rear += 1
    return -1


if __name__ == '__main__':
    N, K = map(int,sys.stdin.readline().rstrip().split(' '))
    stat = list(map(int,sys.stdin.readline().rstrip().split(' ')))
    wannabe = list(map(int,sys.stdin.readline().rstrip().split(' ')))
    push_already(stat,already,0)

    print(bfs())