import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())
arr = deque()
for i in range(N):
    arr.append(i+1)
outnumber = map(int, sys.stdin.readline().split())
total = 0

for output in outnumber:
    cnt = 0
    while (output != arr[cnt]):
        cnt += 1

    if cnt > len(arr)-cnt:
        cnt = len(arr)-cnt
    else:
        cnt *= -1

    # rotate(i)일때 왼쪽으로 i만큼 이동, rotate(-i)일때 오른쪽으로 i만큼 이동
    arr.rotate(cnt)
    total += abs(cnt)
    arr.popleft()

print(total)