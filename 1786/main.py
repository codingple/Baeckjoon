
def get_pi(P):
    n = len(P)
    pi = [0 for _ in range(n)]

    j = 0
    for i in range(1, n):
        while j > 0 and P[i] != P[j]:
            j = pi[j - 1]

        if P[i] == P[j]:
            j += 1
            pi[i] = j
    return pi


def kmp(T, P):
    result = []
    pi = get_pi(P)

    j = 0
    for i in range(len(T)):
        while j > 0 and T[i] != P[j]:
            j = pi[j - 1]

        if T[i] == P[j]:
            j += 1
            if j == len(P):
                result.append(i - j + 2)
                j = pi[j - 1]

    return result

if __name__ == '__main__':
    T = input()
    P = input()
    res = kmp(T,P)
    print(len(res))
    print(*res)