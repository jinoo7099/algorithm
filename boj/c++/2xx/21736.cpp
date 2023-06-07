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

string a[602];
bool vis[602][602];

void solve() {
    int n, m;
    cin >> n >> m;

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'I') {
                x = i;
                y = j;
            }
        }
    }

    queue<pii> q;
    q.push({x, y});
    vis[x][y] = 1;

    int ans = 0;

    while (q.size()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || a[nx][ny] == 'X') continue;

            q.push({nx, ny});
            vis[nx][ny] = 1;

            if (a[nx][ny] == 'P') ans++;
        }
    }

    if (ans > 0)
        cout << ans << endl;
    else
        cout << "TT" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt = 1;
    // cin >> tt;
    while (tt--) solve();

    return 0;
}
