import sys
from collections import deque
n = int(sys.stdin.readline())

dq = deque()

for _ in range(n):
    str = sys.stdin.readline().split()
    if str[0] == 'push_back':
        dq.append(str[1])
    elif str[0] == 'push_front':
        dq.appendleft(str[1])
    elif str[0] == 'pop_front':
        if len(dq) == 0:
            print(-1)
        else:
            print(dq.popleft())
    elif str[0] == 'pop_back':
        if len(dq) == 0:
            print(-1)
        else:
            print(dq.pop())
    elif str[0] == 'size':
        print(len(dq))
    elif str[0] == 'empty':
        if len(dq) == 0:
            print(1)
        else:
            print(0)
    elif str[0] == 'front':
        if len(dq) == 0:
            print(-1)
        else:
            print(dq[0])
    elif str[0] == 'back':
        if len(dq) == 0:
            print(-1)
        else:
            print(dq[-1])