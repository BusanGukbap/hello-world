n = int(input())
arr = list(map(int, input().split()))
stack = []
output = []

for i in range(n):
    while stack:
        if stack[-1][0] > arr[i]:
            output.append(stack[-1][1] + 1)
            break
        else:
            stack.pop()
    if not stack:
        output.append(0)
    stack.append([arr[i], i])

for x in output:
    print(x)