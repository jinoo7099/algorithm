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

int n, m, t;
int arr[55][55];

void rotate(int x, int d) {
    if (d == 0) {
        int tmp = arr[x][m];

        for (int i = m; i > 1; i--) {
            arr[x][i] = arr[x][i - 1];
        }

        arr[x][1] = tmp;
    } else {
        int tmp = arr[x][1];

        for (int i = 1; i < m; i++) {
            arr[x][i] = arr[x][i + 1];
        }
        arr[x][m] = tmp;
    }
}

bool check() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 0) continue;

            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];

                if (ny == 0) ny = m;
                if (ny == m + 1) ny = 1;
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (arr[nx][ny] == arr[i][j]) {
                    return true;
                }
            }
        }
    }

    return false;
}

void removeAdjElement() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 0) continue;

            queue<pii> q;
            int vis[55][55];
            vector<pii> tmp;
            memset(vis, 0, sizeof(vis));

            q.push({i, j});
            tmp.push_back({i, j});
            vis[i][j] = 1;
            int s = arr[i][j];

            while (q.size()) {
                auto cur = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = cur.first + dx[d];
                    int ny = cur.second + dy[d];

                    if (ny == 0) ny = m;
                    if (ny == m + 1) ny = 1;

                    if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                    if (vis[nx][ny] || s != arr[nx][ny]) continue;

                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                    tmp.push_back({nx, ny});
                }
            }

            if (tmp.size() >= 2) {
                for (auto s : tmp) {
                    arr[s.first][s.second] = 0;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> t;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < t; i++) {
        int x, d, k;
        cin >> x >> d >> k;

        for (int j = x; j <= n; j += x) {
            for (int p = 0; p < k; p++) {
                rotate(j, d);
            }
        }

        bool flag = check();

        if (flag) {
            removeAdjElement();
        } else {
            // 평균
            double sum = 0;
            double cnt = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (arr[i][j] == 0) continue;

                    sum += arr[i][j];
                    cnt++;
                }
            }
            sum /= cnt;

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (arr[i][j] == 0) continue;
                    if (sum > arr[i][j]) {
                        arr[i][j]++;
                    } else if (sum < arr[i][j]) {
                        arr[i][j]--;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += arr[i][j];
            // cout << arr[i][j] << ' ';
        }
        // cout << endl;
    }

    cout << ans << endl;
    return 0;
}
