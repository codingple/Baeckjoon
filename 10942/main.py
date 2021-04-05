import sys

def get_z(string):
    n = len(string)
    l = -1
    r = -1

    p = [0 for _ in range(n)]

    for i in range(1,n):
        if i <= r:
            p[i] = min(r-i, p[i-l])
        while i+p[i] < n and string[i+p[i]] == string[p[i]]:
            p[i] += 1
        if r < i+p[i]:
            r = i + p[i]
            l = i

    return p

def get_z2(string):
    l = 0
    r = 0
    n = len(string)
    p = [0 for _ in range(n)]
    for i in range(1,n):
        # r < i이면 기존 정보가 없으므로 하나씩 구해봄
        if r < i:
            l = r = i
            # 일치하는 문자가 존재할 때마다 r을 증가
            while r < n and string[r-l] == string[r]:
                r+=1
            # r 업데이트
            p[i] = r - l
            r -= 1
        # l, r로 기존 매칭 정보 존재
        else:
            # i부터 같은 개수가 r보다 작으면: 이전 데이터 활용 가능
            # i-l은 접두에서 현 위치와 매칭되는 인덱스
            # p[i-l]은 이전에 계산한 접두와 매칭 문자 개수
            # p[i-l] + i - 1은 i위치 기준으로 [l, r]에서의 위치
            if p[i-l] + i - 1 <= r:
                p[i] = p[i-l]
            # [l, r]을 모두 활용했으면, 다시 하나씩 구해봄
            else:
                l = i
                while r < n and string[r-l] == string[r]:
                    r += 1
                    # r 업데이트
                p[i] = r - l
                r -= 1
    return p

if __name__ == '__main__':
    # N = int(sys.stdin.readline().rstrip())
    # numbers = list(map(int, sys.stdin.readline().rstrip().split(' ')))
    # M = int(sys.stdin.readline().rstrip())
    # for _ in range(M):
    #     S, E = list(map(int, sys.stdin.readline().rstrip().split(' ')))
    string = "abcabcabab"
    #         0 1 2 3 4 5 6 7 8 9
    #tring = "a b c a b c a b a b"
    print(get_z2(string))
    print(*string)
