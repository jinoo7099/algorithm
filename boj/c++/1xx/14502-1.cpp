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

int n, m;
vector<vector<int>> d(22, vector<int>(22));
int vis[22][22];
int ans;

void bfs(vector<vector<int>> v) {
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 2) {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }

    while (q.size()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || v[nx][ny] != 0) continue;

            q.push({nx, ny});
            vis[nx][ny] = 1;
            v[nx][ny] = 2;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                cnt++;
            }
        }
    }
    ans = max(ans, cnt);
}

void go(int cur, vector<vector<int>> v) {
    if (cur == 3) {
        bfs(v);
        return;
    }

    vector<vector<int>> t = v;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (t[i][j] == 0) {
                t[i][j] = 1;
                go(cur + 1, t);
                t[i][j] = 0;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];
        }
    }

    go(0, d);

    cout << ans << endl;
    return 0;
}
