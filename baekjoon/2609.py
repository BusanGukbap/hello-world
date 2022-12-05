# 최대공약수
def  gcd(x, y):
    while (y != 0):
        temp = x%y
        x = y
        y = temp
    return x

# 최소공배수
def lcm(x, y, z):
    return int(a * b / z)

a,b = map(int, input().split())
if (a>=b):
    t1 = gcd(a,b)
    t2 = lcm(a, b, t1)
else:
    t1 = gcd(b,a)
    t2 = lcm(b, a, t1)

print(t1, t2, sep='\n')

