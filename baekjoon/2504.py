import sys
s = sys.stdin.readline().strip()
stack = []
total = 0

for i in s:
    score = 0
    if i == ')':
        while len(stack) != 0:
            top = stack.pop()
            if top == '(':
                if (score == 0):
                    stack.append(2)
                else:
                    stack.append(2*score)
                break
            elif top == '[':
                print(0)
                exit(0)
            else:
                score += top

    elif i == ']':
        while len(stack) != 0:
            top = stack.pop()
            if top == '[':
                if (score == 0):
                    stack.append(3)
                else:
                    stack.append(3*score)
                break
            elif top == '(':
                print(0)
                exit(0)
            else:
                score += top

    else:
        stack.append(i)

for i in stack:
    if i == '(' or i=='[':
        print(0)
        exit(0)
    else:
        total += i
print(total)