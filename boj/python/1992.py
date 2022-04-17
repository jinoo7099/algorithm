n = int(input())

lst = []


def check(n, x, y):
    for i in range(n):
        for j in range(n):
            if lst[x][y] != lst[x+i][y+j]:
                return False

    return True


def solve(n, x, y):
    if check(n, x, y):
        print(lst[x][y], end="")
        return

    print("(", end="")

    k = n // 2

    for i in range(0, n, k):
        for j in range(0, n, k):
            solve(k, x + i, y + j)

    print(")", end="")


for _ in range(n):
    lst.append(input())

solve(n, 0, 0)
