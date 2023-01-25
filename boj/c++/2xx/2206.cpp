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
string d[1002];
int vis[1002][1002][2];  // 0 -> block 사용, 1 -> block 사용 안함
int ans = 1e9;

void bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    vis[0][0][1] = 1;

    while (q.size()) {
        auto cur = q.front().first;
        auto block = q.front().second;
        q.pop();
        if (cur.first == n - 1 && cur.second == m - 1) {
            cout << vis[cur.first][cur.second][block];
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            // 1 block
            if (block && d[nx][ny] == '1') {
                q.push({{nx, ny}, block - 1});
                vis[nx][ny][block - 1] = vis[cur.first][cur.second][block] + 1;
            }

            // 0 block
            // 0 not block
            if (d[nx][ny] == '0' && vis[nx][ny][block] == 0) {
                q.push({{nx, ny}, block});
                vis[nx][ny][block] = vis[cur.first][cur.second][block] + 1;
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    bfs();
    return 0;
}
