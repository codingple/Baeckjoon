import sys
from itertools import combinations

if __name__ == '__main__':
    N, M = map(int,sys.stdin.readline().rstrip().split(' '))
    cards = sorted(list(map(int,sys.stdin.readline().rstrip().split(' '))))

    while cards[-1] >= M:
        cards.pop()

    iter = list(combinations(cards,3))

    answer = 0
    for it in iter:
        this_sum = sum(it)
        if this_sum <= M:
            answer = max(this_sum, answer)

    print(answer)