import math

n = 1
while True:
    str = input()
    N = int(str.split()[0])
    F = int(str.split()[1])
    if (N == 0 and F == 0): break

    sum = 0
    for i in range(N):
        sum += int(input())

    print("Bill #", n, " costs ", sum, ": each friend should pay ", sum//F, sep='')
    print()
    n += 1

