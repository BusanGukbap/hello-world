import sys

def dfs(V):
    print(V, end=' ')
    visit[V] = 1
    for i in range(1, N+1):
        if visit[i] == 0 and matrix[V][i] == 1:
            dfs(i)

def bfs(V):
    queue=[V]
    visit[V] = 0
    while(queue):
        V = queue[0]
        del queue[0]
        print(V, end=' ')
        for i in range(1, N+1):
            if visit[i] == 1 and matrix[V][i] == 1:
                queue.append(i)
                visit[i] = 0


N, M, V = map(int, sys.stdin.readline().split())
matrix = [[0]*(N+1) for i in range(1+N)]
visit = [0 for i in range(1+N)]
for i in range(M):
    x, y = map(int, sys.stdin.readline().split())
    matrix[x][y] = 1
    matrix[y][x] = 1

dfs(V)
print()
bfs(V)