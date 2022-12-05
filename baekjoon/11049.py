import sys
N = int(sys.stdin.readline())
matrix = [list(map(int, sys.stdin.readline().split())) for i in range(N)]
dp = [[0]*(N) for i in range(N)]

for i in range(1, N):
    for y in range(N-i):
        x = i+y
        dp[y][x] = 2**32
        for k in range(y, x):
            dp[y][x] = min(dp[y][x], dp[y][k] + dp[k+1][x] + matrix[y][0] * matrix[x][1] * matrix[k][1])

print(dp[0][N-1])