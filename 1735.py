#최대공약수
def gcd(x,y):
    while y!=0:
        temp = x%y
        x = y
        y = temp
    return x

#최소공배수
def lcm(x, y):
    temp = gcd(x,y)
    return x*y//temp

A1, B1 = map(int, input().split())
A2, B2 = map(int, input().split())
mom = lcm(B1, B2)
son = mom//B1*A1 + mom//B2*A2
temp = gcd(son, mom)
print(son//temp, mom//temp)