def gcd(x, y):
    while(y != 0):
        temp = x%y
        x = y
        y = temp
    return x

def circle(a, b):
    temp = gcd(a, b)
    print(a//temp, '/', b//temp, sep='')


N = int(input())
arr = list(map(int, input().split()))
for i in range(1, N):
    circle(arr[0], arr[i])