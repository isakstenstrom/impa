from sys import stdin

multiplicatior = 1.32471795724475

for line in stdin:
    i = int(line)
    if (i == 1): print(1)
    elif (i <= 3): print(2)
    else:
        sum = 2
        for n in range(3,i):
            sum = round(sum*multiplicatior)
        print(sum)

