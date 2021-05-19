import operator as op
from functools import reduce

def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer // denom

K = int(input())
for k in range(K):
    (N, T, P) = tuple(map(int, input().split()))
    X = T - N*P
    if X < 0:
        print(0)
    else:
        print(ncr(X + N - 1, X))