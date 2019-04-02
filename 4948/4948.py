def isPrime(x):
    for i in range(2,x):
        if x % i == 0:
            return False
    return True

inputs = list()
n = int(input())
while n != 0:
    inputs.append(n)
    n = int(input())

end = 246912
all = list(range(1, end+1))

p=2
i=2*p-1
while i < end:
    all[i] = -1
    i += 2

p = 3
i=2*p-1
while p*p < end:
    i=2*p-1
    while i < end:
        all[i] = -1
        i += p

    p += 2
    while all[p-1] == -1 or not isPrime(p):
        p += 2

for n in inputs:
    end = 2*n
    print( len( [all[x] for x in range(n, end) if all[x] != -1] ) )