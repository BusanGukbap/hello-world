import sys
from collections import deque

def rotation(direction, c):
    # L 왼쪽으로 90도 회전
    if c == "L":
        direction = (direction+1)%4
    # D 오른쪽으로 90도 회전
    else:
        direction = (direction-1)%4
    return direction

dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]

N = int(sys.stdin.readline())
K = int(sys.stdin.readline())
arr = [[0] * N for _ in range(N)]
for _ in range(K):
    a, b = map(int, sys.stdin.readline().split())
    arr[a - 1][b - 1] = 1  # 사과 저장
L = int(sys.stdin.readline())
times = {}
for i in range(L):
    X, C = map(str, sys.stdin.readline().split())
    times[int(X)] = C

direction = 0
time = 1
y, x = 0, 0
visited = deque([[y, x]])
arr[y][x] = 2
while True:
    x = x+dx[direction]
    y = y+dy[direction]
    # not Game Over
    if 0 <= y < N and 0 <= x < N and arr[y][x] != 2:
        # not apple
        if arr[y][x] != 1:
            temp_y, temp_x = visited.popleft()
            # tail is moving
            arr[temp_y][temp_x] = 0
        # head is moving
        arr[y][x] = 2
        # 머리 현 위치 덱에 추가
        visited.append([y,x])
        if time in times.keys():
            direction = rotation(direction, times[time])
        time += 1
    #Game Over
    else:
        break
print(time)