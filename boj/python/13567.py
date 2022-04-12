n, m = map(int, input().split())
dir = 0
x, y = 0, 0
flag = False
for _ in range(m):
    s, t = input().split()
    t = int(t)
    if s == "TURN":
        if(t == 0):
            dir = (dir + 3) % 4
        else:
            dir = (dir + 1) % 4
    else:
        if(dir == 0):
            x = x + t
        elif(dir == 1):
            y = y - t
        elif(dir == 2):
            x = x - t
        elif(dir == 3):
            y = y + t
    if(x < 0 or x > n or y < 0 or y > n):
        print(-1)
        flag = True
        break

if flag == False:
    print(x, y)
