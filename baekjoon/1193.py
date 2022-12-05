import sys
n = int(sys.stdin.readline())
cnt = 1
while(n-cnt > 0):
    n -= cnt
    cnt += 1

if cnt%2 == 0:
    print(n, '/', cnt-n+1, sep='')

else:
    print(cnt-n+1, '/', n, sep='')