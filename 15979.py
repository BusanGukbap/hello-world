def gcd(a, b):
    if (a == 0 or b == 0):
        return a+b
    if (a>b):
        return gcd(a%b, b)
    return gcd(b%a, a)

N, M = map(int, input().split())
if (N < 0):
    N *= -1
if (M < 0):
    M *= -1

if (N==0 and M==0):
    print(0)
elif (gcd(M, N) > 1):
    print(2)
else:
    print(1)