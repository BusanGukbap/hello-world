A, B, V = map(int, input().split())
V -= A
count = V // (A-B)
if V%(A-B) > 0:
    count += 1
print(count+1)