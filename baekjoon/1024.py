import sys
N, L = map(int, sys.stdin.readline().split())
Len = L
while True:
    arr = [0] * L
    for i in range(L):
        arr[i] = i
    
    temp = N-sum(arr)
    if (temp % L == 0 and (arr[0]+temp//L >= 0)):
        for i in range(L):
            print(arr[i]+temp//L, end=' ')
        break
    else:
        L += 1
    
    if (L > 100):
        print(-1)
        break