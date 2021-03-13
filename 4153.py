import sys

while True:
    a, b, c = map(int, sys.stdin.readline().split())
    if a == b == c == 0:
        break
    a *= a
    b *= b
    c *= c
    if (a+b == c) or (a+c == b) or (b+c == a):
        print("right")
    else:
        print("wrong")