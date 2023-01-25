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

int vis[1002][1002][12];
int d[1002][1002];
int n, m, k;
int ans = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            d[i][j] = s[j] - '0';
        }
    }

    queue<pair<pii, int>> q;
    q.push({{0, 0}, k});
    vis[0][0][k] = 1;

    while (q.size()) {
        auto cur = q.front().first;
        int block = q.front().second;
        q.pop();

        if (cur.first == n - 1 && cur.second == m - 1) {
            cout << vis[n - 1][m - 1][block] << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (d[nx][ny] == 1 && block && vis[nx][ny][block - 1] == 0) {
                q.push({{nx, ny}, block - 1});
                vis[nx][ny][block - 1] = vis[cur.first][cur.second][block] + 1;
            }
            if (d[nx][ny] == 0 && vis[nx][ny][block] == 0) {
                q.push({{nx, ny}, block});
                vis[nx][ny][block] = vis[cur.first][cur.second][block] + 1;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
