#최대 공약수
def gcd(x, y):
    while(y!=0):
        temp = x%y
        x = y
        y = temp
    return x

T = int(input())
for i in range(T):
    A, B = map(int, input().split())
    print(A*B//gcd(A,B), sep="\n")