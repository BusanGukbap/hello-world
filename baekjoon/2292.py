n = int(input())
temp = 6
count = 1

while (n-1 > 0):
    n -= temp
    count += 1
    temp += 6
print(count)