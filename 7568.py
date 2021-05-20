import sys
n = int(sys.stdin.readline())

student = []
for _ in range(n):
    weight, tall = map(int, sys.stdin.readline().split())
    student.append((weight, tall))

for i in student:
    temp = 1
    for j in student:
        if i[0]<j[0] and i[1]<j[1]:
            temp += 1
    print(temp, end=' ')
