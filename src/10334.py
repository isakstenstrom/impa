from sys import stdin

for line in stdin:
    n = int(line)
    a = 0
    b = 1
    tmp = 0
    for i in range(n):
        tmp = a + b
        a = b
        b = tmp
    print(a+b)