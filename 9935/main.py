import sys
from collections import deque

if __name__ == '__main__':
    string = sys.stdin.readline().rstrip()
    bomb = sys.stdin.readline().rstrip()
    N = len(bomb)
    i = 0
    idx = 0
    q = deque()

    for i in string:
        q.append(i)
        if len(q) >= N:
            same = True
            for i in range(-1,-N-1,-1):
                if q[i] != bomb[i]:
                    same = False
                    break
            if same:
                for _ in range(N):
                    q.pop()

    string = ''.join(q)

    if string:
        print(string)
    else:
        print("FRULA")