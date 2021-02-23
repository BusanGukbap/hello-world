x, y, w, h = map(int, input().split())
if x>(w-x):
    temp1 = w-x
else:
    temp1 = x
if y>h-y:
    temp2 = h-y
else:
    temp2 = y

if temp1>temp2:
    print(temp2)
else:
    print(temp1)