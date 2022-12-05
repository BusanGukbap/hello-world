while(True):
    x = int(input())
    if (x==0):
        break
    temp = list(str(x))
    temp2 = list(str(x))
    temp.reverse()
    if (temp == temp2):
        print('yes')
    else:
        print('no')