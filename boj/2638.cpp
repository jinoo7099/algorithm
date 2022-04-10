#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define X first
#define Y second

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, ans;
int dist[102][102];
int vis[102][102];
int tmp[102][102];

void bfs(int x, int y) {
    vis[x][y] = 1;

    int cnt = 0;
    for (int j = 0; j < 4; j++) {
        int nxx = x + dx[j];
        int nyy = y + dy[j];

        if (nxx < 0 || nxx >= n || nyy < 0 || nyy >= m) continue;
        if (vis[nxx][nyy] == 0) cnt++;
    }
    if (cnt >= 2)
        tmp[x][y] = 0;
}

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> dist[i][j];
        }
    }

    while (1) {
        ans++;
        memset(vis, -1, sizeof(vis));
        memcpy(tmp, dist, sizeof(dist));

        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == -1 && dist[i][j] == 0) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = 0;

                    while (!q.empty()) {
                        auto cur = q.front();
                        q.pop();

                        for (int i = 0; i < 4; i++) {
                            int nx = cur.first + dx[i];
                            int ny = cur.second + dy[i];

                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if (vis[nx][ny] == 0 || dist[nx][ny] == 1) continue;

                            q.push({nx, ny});
                            vis[nx][ny] = 0;
                        }
                    }
                    flag = true;
                }
                if (flag)
                    break;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == -1 && dist[i][j] == 1)
                    bfs(i, j);
            }
        }

        memcpy(dist, tmp, sizeof(tmp));
        if (check())
            break;
    }

    cout << ans << endl;
    return 0;
}
