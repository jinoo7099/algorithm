from collections import deque


n, m = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(n)]
dx, dy = [-1, 0, 1, 0], [0, 1, 0, -1]
ans = 0
max_picture = 0
vis = [[0] * m for _ in range(n)]

for i in range(n):
    for j in range(m):
        if arr[i][j] == 1 and vis[i][j] == 0:
            queue = deque([])
            queue.append([i, j])
            vis[i][j] = 1
            cnt = 0
            ans += 1

            while queue:
                cnt += 1
                x, y = queue.popleft()

                for d in range(4):
                    nx = x + dx[d]
                    ny = y + dy[d]

                    if nx < 0 or nx >= n or ny < 0 or ny >= m:
                        continue
                    if vis[nx][ny] == 1 or arr[nx][ny] == 0:
                        continue

                    queue.append([nx, ny])
                    vis[nx][ny] = 1
            max_picture = max(max_picture, cnt)

print(ans)
print(max_picture)
