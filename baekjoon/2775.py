def appartment(a, b):
    if a == 0:
        return b
    elif b == 1:
        return 1
    else:
        return appartment(a-1, b) + appartment(a, b-1)

import sys
T = int(sys.stdin.readline())
for _ in range(T):
    k = int(sys.stdin.readline())
    n = int(sys.stdin.readline())
    print(appartment(k, n))