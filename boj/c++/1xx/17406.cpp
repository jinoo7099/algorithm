#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, k;
int arr[52][52];
pair<int, pair<int, int>> ops[10];
int ans = 1e9;
int vis[10];

vector<vector<int>> rotate(int idx) {
    int r = ops[idx].first;
    int c = ops[idx].second.first;
    int s = ops[idx].second.second;
    vector<vector<int>> tmp(n + 2, vector<int>(m + 2));
    tmp[r][c] = arr[r][c];

    int t = s;
    while (t) {
        int st_x = r - t;
        int st_y = c - t;

        int d = 0;
        int x, y;
        x = st_x;
        y = st_y;

        while (d != 4) {
            for (int i = 0; i < 2 * t; i++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                tmp[x][y] = arr[nx][ny];

                x = nx;
                y = ny;
            }

            d++;
        }
        t--;
    }
    return tmp;
}

void solve(int cur) {
    if (cur == k) {
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            for (int j = 1; j <= m; j++) {
                sum += arr[i][j];
            }
            ans = min(ans, sum);
        }
        return;
    }

    for (int i = 0; i < k; i++) {
        if (vis[i]) continue;

        vector<vector<int>> origin(n + 2, vector<int>(m + 2));
        vector<vector<int>> tmp = rotate(i);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                origin[i][j] = arr[i][j];
                if (tmp[i][j])
                    arr[i][j] = tmp[i][j];
            }
        }
        vis[i] = 1;
        solve(cur + 1);
        // 다시 rotate
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                arr[i][j] = origin[i][j];
            }
        }
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        ops[i] = {r,
                  {c, s}};
    }

    solve(0);

    cout << ans << endl;

    return 0;
}
