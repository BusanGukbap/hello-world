import sys
x1, y1 = map(int, sys.stdin.readline().split())
x2, y2 = map(int, sys.stdin.readline().split())
x3, y3 = map(int, sys.stdin.readline().split())

if (x1 == x2):
    last_x = x3
elif x2 == x3:
    last_x = x1
elif x1 == x3:
    last_x = x2

if y1 == y2:
    last_y = y3
elif y1 == y3:
    last_y = y2
elif y2 == y3:
    last_y = y1

print(last_x, last_y)