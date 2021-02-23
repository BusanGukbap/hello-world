import sys
N, M = map(int, input().split())

map = []
for i in range(N):
    map.append(input())

fixing = []
for i in range(N-7):
    for j in range(M-7):
        different = 0
        first = map[i][j]
        for x in range(i, i+8):
            for y in range(j, j+8):
                if ((x+y)%2 == 0) and (first != map[x][y]):
                    different += 1
                elif ((x+y)%2 == 1) and (first == map[x][y]):
                    different += 1
        fixing.append(different)
        fixing.append(64-different)
print(min(fixing))