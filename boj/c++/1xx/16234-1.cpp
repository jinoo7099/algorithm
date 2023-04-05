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

int n, l, r;
int arr[52][52];
int vis[52][52];

int bfs(int x, int y, int k) {
    queue<pii> q;
    q.push({x, y});
    vis[x][y] = k;
    vector<pii> dists;
    int cnt = 0;

    while (q.size()) {
        cnt++;
        auto cur = q.front();
        dists.push_back(cur);
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (vis[nx][ny] > 0) continue;

            int d = abs(arr[cur.first][cur.second] - arr[nx][ny]);
            if (l <= d and d <= r) {
                vis[nx][ny] = k;
                q.push({nx, ny});
            }
        }
    }

    if (cnt < 2) return cnt;

    int sum = 0;
    for (auto d : dists) {
        sum += arr[d.first][d.second];
    }

    for (auto d : dists) {
        arr[d.first][d.second] = sum / dists.size();
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    int ans = 0;
    while (ans < 2000) {
        memset(vis, 0, sizeof(vis));
        int k = 1;
        bool ch = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (vis[i][j] == 0) {
                    int cnt = bfs(i, j, k);
                    if (cnt > 1) ch = true;
                    k++;
                }
            }
        }

        if (!ch) break;
        ans++;
    }
    cout << ans << endl;

    return 0;
}
