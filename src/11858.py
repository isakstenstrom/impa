from sys import stdin

def mergeSortInversions(arr):
    if len(arr) == 1:
        return arr, 0
    else:
        a = arr[:len(arr)//2]
        b = arr[len(arr)//2:]
        a, ai = mergeSortInversions(a)
        b, bi = mergeSortInversions(b)
        c = []
        i = 0
        j = 0
        inversions = 0 + ai + bi
    while i < len(a) and j < len(b):
        if a[i] <= b[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1
            inversions += (len(a)-i)
    c += a[i:]
    c += b[j:]
    return c, inversions

n = 0
arr = []
for line in stdin:
    if n == 0:
        n = int(line[:-1])
        arr = []
    else:
        arr.append(int(line[:-1]))
        n -= 1
        if n == 0:
            stuff, inversions = mergeSortInversions(arr)
            print(inversions)