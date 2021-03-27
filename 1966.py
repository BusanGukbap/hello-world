import sys

TestCase = int(sys.stdin.readline())
for _ in range(TestCase):
    # n은 문서 개수, m은 몇번재로 인쇄되는지 궁금한 문서의 현재 위치
    n, m = map(int, sys.stdin.readline().split())
    A = list(map(int, sys.stdin.readline().split()))
    cnt = 0
    while (1):
        if (max(A) == A[0]):
            cnt += 1
            if (m == 0):
                print(cnt)
                break
            else:
                A.pop(0)
                m -= 1
        elif (max(A) > A[0]):
            A.append(A.pop(0))
            if (m == 0):
                m += len(A)-1
            else:
                m -= 1
        