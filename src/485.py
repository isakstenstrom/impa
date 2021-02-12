import math

n = 0
max_num = 0
while True:    
    for k in range(n+1):
        num = math.factorial(n)//(math.factorial(k)* math.factorial(n - k))
        max_num = max(max_num, num)
        print(num, end='')
        if (k != n): print(' ', end='')

    print()
    if (max_num >= 1e60): break
    n += 1
