#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int n, m;
int a[200][200];
int vis[200][200];
pair<int, int> d[200];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> d[i].fi >> d[i].se;
    }

    vis[n - 1][0] = vis[n - 1][1] = vis[n - 2][0] = vis[n - 2][1] = 1;

    for (int i = 0; i < m; i++) {
        int dir = d[i].first;
        int s = d[i].second;
        int tmp[200][200];

        for (int ii = 0; ii < n; ii++) {
            for (int jj = 0; jj < n; jj++) {
                int nx = (ii + dx[dir - 1] * s % n + n) % n;
                int ny = (jj + dy[dir - 1] * s % n + n) % n;

                tmp[nx][ny] = vis[ii][jj];
            }
        }

        for (int ii = 0; ii < n; ii++) {
            for (int jj = 0; jj < n; jj++) {
                if (tmp[ii][jj]) {
                    a[ii][jj]++;
                }
            }
        }

        for (int ii = 0; ii < n; ii++) {
            for (int jj = 0; jj < n; jj++) {
                if (!tmp[ii][jj]) continue;
                for (int k = 0; k < 4; k++) {
                    // 1 3 5 7
                    int nx = ii + dx[2 * k + 1];
                    int ny = jj + dy[2 * k + 1];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (a[nx][ny]) {
                        a[ii][jj]++;
                    }
                }
            }
        }

        memset(vis, 0, sizeof(vis));

        for (int ii = 0; ii < n; ii++) {
            for (int jj = 0; jj < n; jj++) {
                if (a[ii][jj] >= 2 && !tmp[ii][jj]) {
                    vis[ii][jj] = 1;
                    a[ii][jj] -= 2;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += a[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
