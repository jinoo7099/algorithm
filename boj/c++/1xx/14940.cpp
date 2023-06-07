#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int a[1002][1002];
int vis[1002][1002];

// 10 ^ 6 * 10 ^ 6 -> bf

void solve() {
    int n, m;
    cin >> n >> m;

    int x, y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                x = i;
                y = j;
            }
        }
    }

    for (int i = 0; i < 1001; i++) {
        fill(vis[i], vis[i] + 1001, -1);
    }

    queue<pii> q;
    q.push({x, y});
    vis[x][y] = 0;

    while (q.size()) {
        auto cur = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] != -1 || a[nx][ny] == 0) continue;

            q.push({nx, ny});
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0)
                cout << 0 << ' ';
            else if (vis[i][j] == -1)
                cout << -1 << ' ';
            else
                cout << vis[i][j] << ' ';
        }

        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt = 1;
    // cin >> tt;
    while (tt--) solve();

    return 0;
}
