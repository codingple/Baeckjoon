import sys

if __name__ == '__main__':
    string = map(ord, sys.stdin.readline().rstrip())
    cnt = [0 for _ in range(26)]
    little = ord('a')
    prime = ord('A')
    for c in string:
        if c < little:
            cnt[c - prime] += 1
        else:
            cnt[c - little] += 1

    maxi = 0
    maxi_idx = 0
    maxi_cnt = 0
    for i in range(26):
        if cnt[i] > maxi:
            maxi = cnt[i]
            maxi_idx = i
            maxi_cnt = 1
        elif maxi == cnt[i]:
            maxi_cnt += 1

    if maxi_cnt > 1:
        print('?')
    else:
        print( chr(maxi_idx + prime) )