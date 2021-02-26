import sys
n = int(sys.stdin.readline())

people = []
for _ in range(n):
    age, name = map(str, input().split())
    age = int(age)
    people.append((age, name))

people.sort(key = lambda x : x[0])

for x in people:
    print(x[0], x[1])