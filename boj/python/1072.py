import sys


x, y = map(int, input().split())

d = int(y * 100 // x)
ans = 0

if d >= 99:
    print(-1)
else:
    ans = 0
    low, high = 1, x

    while low <= high:
        mid = low + (high - low) // 2

        k = int((y + mid) * 100 // (x + mid))

        if(k <= d):
            low = mid + 1
        else:
            ans = mid
            high = mid - 1

    print(ans)
