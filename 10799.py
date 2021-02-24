import sys
str = sys.stdin.readline().strip()
arr = []
before = ' '
total = 0
for i in range(len(str)):
    if str[i] == '(':
        arr.append(1)
    else:
        if before == '(':
            arr.pop()
            total += sum(arr)
        elif before == ')':
            total += 1
            arr.pop()
    before = str[i]

print(total)