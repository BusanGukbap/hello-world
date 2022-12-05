import sys
S = set()
total = set()
for i in range(1, 21):
    total.add(i)
M = int(sys.stdin.readline())
for _ in range(M):
    temp = sys.stdin.readline().strip().split()

    if temp[0] == "add":
        S.add(int(temp[1]))

    elif temp[0] == "remove":
        # remove 사용시 없는 것을 지울려고 하면 keyError
        S.discard(int(temp[1]))

    elif temp[0] == "check":
        if int(temp[1]) in S:
            print(1)
        else:
            print(0)

    elif temp[0] == "toggle":
        if int(temp[1]) in S:
            S.discard(int(temp[1]))
        else:
            S.add(int(temp[1]))

    elif temp[0] == "all":
        S = total

    elif temp[0] == "empty":
        S = set()
