import sys

N, M = map(int, sys.stdin.readline().split())

unheard = set()
unseen = set()
total = 0

for i in range(N):
    unheard.add(sys.stdin.readline().rstrip())
for i in range(M):
    unseen.add(sys.stdin.readline().rstrip())

arr = list(unheard&unseen)
print(len(arr))
arr.sort()
for i in arr:
    print(i)