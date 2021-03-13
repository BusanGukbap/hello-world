import sys
N, r, c = map(int, sys.stdin.readline().split())
# r = 행, c = 열
result = 0
index = 2**(N-1)
while index:
    if (r >= index):
        result += index*index*2
        r -= index
    if (c >= index):
        result += index*index
        c -= index
    index //= 2

print(result)