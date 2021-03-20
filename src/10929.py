import math

while True:
    n = input()
    N = int(n)
    if N == 0: 
        break
    print(n.strip(), end=' ')
    print('is', end=' ')
    if (N % 11 != 0): 
        print('not', end=' ')
    print('a multiple of 11.')

