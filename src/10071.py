from sys import stdin

for line in stdin:
    [v, t] = map(int, line.split())
    print(v*t*2)
