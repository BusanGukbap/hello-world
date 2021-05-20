import sys
from collections import deque

def bfs():
    q = deque()
    q.append(N)
    while(q):
        v = q.popleft()
        if v == K:
            print(time[v])
            break
        for i in (v-1, v+1, v*2):
            if 0<=i<=100000 and not time[i]:
                time[i] = time[v]+1
                q.append(i)

N, K = map(int, sys.stdin.readline().split())
time = [0]*100001
bfs()