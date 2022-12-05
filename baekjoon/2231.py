N = int(input())
result = 0
for i in range(1, N+1):
    if (i==N):
        print(0)
        break

    result = i
    temp = i
    while (temp != 0):
        result += temp%10
        temp //= 10
    if (result == N):
        print(i)
        break