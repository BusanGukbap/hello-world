def gcd(x, y):
    while(y!=0):
        temp = x%y
        x = y
        y = temp
    return x

N = int(input())
arr = [0]*N
for i in range(N):
    arr[i] = int(input())

temp = (arr[1]-arr[0])
for i in range(2, N):
    temp = gcd(temp, arr[i]-arr[i-1])

print((arr[N-1]-arr[0])//temp - N + 1)