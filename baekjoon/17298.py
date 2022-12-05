import sys
n = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))

stack = []
result = [-1 for _ in range(n)]

for i in range(n):
    while stack and A[stack[-1]] < A[i]:
        result[stack.pop()] = A[i]
    
    stack.append(i)

for i in range(n):
    print(result[i], end=' ')