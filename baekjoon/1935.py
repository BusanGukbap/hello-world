N = int(input())
str = input()
arr = []
for i in range(N):
    arr.append(int(input()))

stack = []
for temp in str:
    if temp == '+':
        num = stack.pop()
        stack[-1] += num
    elif temp == '*':
        num = stack.pop()
        stack[-1] *= num
    elif temp == '-':
        num = stack.pop()
        stack[-1] -= num

    elif temp == '/':
        num = stack.pop()
        stack[-1] /= num

    else:
        stack.append(arr[ord(temp)-ord('A')])

print('%.2f' % stack[-1])