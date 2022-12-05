import sys

n = int(input())
s = []

for _ in range(n):
    temp = sys.stdin.readline().strip()
    s.append((temp, len(temp)))
    
s = list(set(s))
s.sort(key=lambda x: (x[1], x[0]))
for i in s:
    print(i[0])