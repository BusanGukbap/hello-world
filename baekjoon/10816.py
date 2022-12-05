import sys
N = int(sys.stdin.readline())
arr1 = map(int, sys.stdin.readline().split())
M = int(sys.stdin.readline())
arr2 = map(int, sys.stdin.readline().split())

hashmap = {}
for n in arr1:
    if n in hashmap:
        hashmap[n] += 1
    else:
        hashmap[n] = 1

# print(' '.join(str(hashmap[m]) if m in hashmap else '0' for m in arr2))

for x in arr2:
    if x in hashmap:
        print(hashmap[x], end=' ')
    else:
        print('0', end=' ')