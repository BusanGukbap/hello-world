import sys
from collections import Counter
n = int(sys.stdin.readline())
arr = [0]*n
for i in range(n):
    arr[i] = int(sys.stdin.readline())

if sum(arr)/n - sum(arr)//n < 0.5:
    print(sum(arr)//n)
else:
    print(sum(arr)//n + 1)
arr.sort()
print(arr[n//2])
cnt = Counter(arr)
mode = cnt.most_common()
if len(mode) > 1:
    if (mode[0][1] == mode[1][1]):
        print(mode[1][0])
    else:
        print(mode[0][0])
else:
    print(mode[0][0])
print(max(arr)-min(arr))