T = int(input())
for i in range(T):
    H, W, N = map(int, input().split())
    if (N%H == 0):
        result = H * 100
        result += N//H
    else:
        result = N%H
        result *= 100
        result += N//H + 1
    print(result)