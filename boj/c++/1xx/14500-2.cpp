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

int n, m;
int arr[502][502];
int vis[502][502];
int ans;

void dfs(int cur, int x, int y, int sum) {
    if (cur == 4) {
        ans = max(ans, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (vis[nx][ny]) continue;

        vis[nx][ny] = 1;
        dfs(cur + 1, nx, ny, sum + arr[nx][ny]);
        vis[nx][ny] = 0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vis[i][j] = 1;
            dfs(1, i, j, arr[i][j]);
            vis[i][j] = 0;

            // ㅏ
            if (i - 1 >= 1 and i + 1 <= n and j + 1 <= m) {
                ans = max(ans, arr[i][j] + arr[i - 1][j] + arr[i + 1][j] + arr[i][j + 1]);
            }
            // ㅓ
            if (i - 1 >= 1 and i + 1 <= n and j - 1 >= 1) {
                ans = max(ans, arr[i][j] + arr[i - 1][j] + arr[i + 1][j] + arr[i][j - 1]);
            }
            // ㅜ
            if (i + 1 <= n and j - 1 >= 1 and j + 1 <= m) {
                ans = max(ans, arr[i][j] + arr[i + 1][j] + arr[i][j - 1] + arr[i][j + 1]);
            }
            // ㅗ
            if (i - 1 >= 1 and j - 1 >= 1 and j + 1 <= m) {
                ans = max(ans, arr[i][j] + arr[i - 1][j] + arr[i][j - 1] + arr[i][j + 1]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
