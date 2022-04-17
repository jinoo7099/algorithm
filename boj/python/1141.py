n = int(input())

lst = [input() for _ in range(n)]

lst.sort(key=len)

ans = 0

for i in range(n):
    check = False

    for j in range(i+1, n):
        if lst[i] == lst[j][:len(lst[i])]:
            check = True
            break

    if check == False:
        ans += 1

print(ans)
