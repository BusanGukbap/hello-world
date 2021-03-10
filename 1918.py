import sys
input = sys.stdin.readline().strip()
stack = []
output = ''

for x in input:
    if x == '+' or x == '-':
        while stack and stack[-1] != '(':
            output += stack.pop()
        stack.append(x)
    elif x == '*' or x == '/':
        while stack and (stack[-1]=='*' or stack[-1]=='/'):
            output += stack.pop()
        stack.append(x)
    elif x == '(':
        stack.append(x)
    elif x == ')':
        while stack and stack[-1] != '(':
            output += stack.pop()
        stack.pop()
    else:
        output += x

while stack:
    output += stack.pop()

print(output)