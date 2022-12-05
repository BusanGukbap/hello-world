import sys

n , m = map(int, sys.stdin.readline().split())
pokemon = dict()
pokemon_reverse = dict()

for i in range(n):
    name = str(sys.stdin.readline().strip())
    pokemon[name] = i+1
    pokemon_reverse[i+1] = name

for _ in range(m):
    temp = str(sys.stdin.readline().strip())
    try:
        print(pokemon[temp])
    except:
        print(pokemon_reverse[int(temp)])