import sys
from collections import deque
N, K = map(int, sys.stdin.readline().split())

Q = deque()
output = '<'
for i in range(1, 1+N):
    Q.append(i)

while len(Q)>1:
    for _ in range(K-1):
        Q.append(Q.popleft())
    output += str(Q.popleft())
    output += ', '
output += str(Q.pop())
output += '>'
print(output)