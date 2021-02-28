n = int(input())

stack = [0]
count = 1
output = []

for i in range(n):
    num = int(input())
    if (count <= num):
        while (num >= count):
            stack.append(count)
            count += 1
            output.append('+')
        stack.pop()
        output.append('-')
    elif (num == stack[-1]):
        stack.pop()
        output.append('-')
    else:
        print('NO')
        exit(0)

for x in output:
    print(x)