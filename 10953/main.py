import sys

if __name__ == '__main__':
    N = int(sys.stdin.readline().rstrip())
    for _ in range(N):
        print(sum(list(map(int,sys.stdin.readline().rstrip().split(',')))))