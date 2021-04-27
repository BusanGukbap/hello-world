import sys
min, max = map(int, sys.stdin.readline().split())
arr = [1 for i in range(max-min+1)]

cnt = 2
while ((cnt*cnt) <= max):
    temp = cnt*cnt
    temp2 = (min//temp)*temp
    if temp2 != min:
        temp2 += temp
    
    while (temp2 <= max):
        arr[temp2-min] = 0
        temp2 += temp
    cnt += 1
    

cnt = 0
for i in range(max-min+1):
    if arr[i] == 1:
        cnt += 1
print(cnt)