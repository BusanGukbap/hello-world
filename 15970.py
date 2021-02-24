import sys

# data input
N = int(input())
arr = []
for j in range(N):
    arr.append(list(map(int, sys.stdin.readline().split())))

arr.sort()
total = 0

# # problem solving
for i in range(N):
    result = 100000
    for j in range(i+1, N):
        if (arr[j][1] == arr[i][1]) and (result > arr[j][0]-arr[i][0]):
            result = arr[j][0]-arr[i][0]
    for j in range(i-1, -1, -1):
        if (arr[j][1] == arr[i][1]) and (result > arr[i][0]-arr[j][0]):
            result = arr[i][0]-arr[j][0]
    total += result
print(total)