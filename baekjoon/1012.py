import sys
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def dfs(x,y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if (0 <= nx < N) and (0 <= ny < M):
            if matrix[nx][ny] == 1:
                matrix[nx][ny] = -1
                dfs(nx, ny)

T = int(sys.stdin.readline())
for _ in range(T):
    M, N, K = map(int, sys.stdin.readline().split())
    matrix = [[0] * M for i in range(N)]
    cnt = 0

    for i in range(K):
        a, b = map(int, sys.stdin.readline().split())
        matrix[b][a] = 1
    
    for i in range(N):
        for j in range(M):
            if matrix[i][j] > 0:
                dfs(i, j)
                cnt += 1
    print(cnt)