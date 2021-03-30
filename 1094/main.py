import sys
import heapq
from itertools import combinations


if __name__ == '__main__':
    X = int(sys.stdin.readline().rstrip())

    pq = []

    heapq.heappush(pq,2 ** 8)
    cnt = 0

    while X != sum(pq):
        crnt_min = heapq.heappop(pq)
        half = crnt_min >> 1
        heapq.heappush(pq,half)
        if sum(pq) < X:
            heapq.heappush(pq, half)

    print(len(pq))