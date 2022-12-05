import sys
k, n = map(int, sys.stdin.readline().split())
A = [int(sys.stdin.readline()) for _ in range(k)]

low  = 1
high = max(A)
result = -1

# 이분탐색 조건
while low <= high:
    mid = (low + high)//2
    temp = 0
    for i in range(k):
        temp += A[i]//mid
    
    if temp >= n:
        if result < mid:
            result = mid
        low = mid + 1
    else:
        high = mid - 1

print(result)