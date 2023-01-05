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

int d[502][502];
int vis[502][502];
int n, m, ans;

void dfs(int cur, int x, int y, int sum) {
    if (cur == 4) {
        ans = max(ans, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (vis[nx][ny]) continue;

        vis[nx][ny] = 1;
        dfs(cur + 1, nx, ny, sum + d[nx][ny]);
        vis[nx][ny] = 0;
    }

    // ㅗ ㅏ ㅜ ㅓ
    // ㅗ
    if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < m) {
        ans = max(ans, d[x][y] + d[x - 1][y] + d[x][y - 1] + d[x][y + 1]);
    }

    // ㅏ
    if (x - 1 >= 0 && x + 1 < n && y + 1 < m) {
        ans = max(ans, d[x][y] + d[x - 1][y] + d[x + 1][y] + d[x][y + 1]);
    }

    // ㅜ
    if (y - 1 >= 0 && x + 1 < n && y + 1 < m) {
        ans = max(ans, d[x][y] + d[x][y - 1] + d[x + 1][y] + d[x][y + 1]);
    }

    // ㅓ
    if (y - 1 >= 0 && x - 1 >= 0 && x + 1 < n) {
        ans = max(ans, d[x][y] + d[x][y - 1] + d[x - 1][y] + d[x + 1][y]);
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = 1;
            dfs(1, i, j, d[i][j]);
            vis[i][j] = 0;
        }
    }

    cout << ans << endl;

    return 0;
}
