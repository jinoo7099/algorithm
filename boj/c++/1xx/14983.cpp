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

int n, m, r;
int item[102];
int d[102][102];

void solve() {
    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++) {
        cin >> item[i];
    }

    for (int i = 1; i <= n; i++) {
        fill(d[i], d[i] + n + 1, 1e9);
        d[i][i] = 0;
    }

    for (int i = 0; i < r; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;

        d[a][b] = cost;
        d[b][a] = cost;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int cnt = item[i];

        for (int j = 1; j <= n; j++) {
            if (i == j) continue;

            if (d[i][j] <= m) {
                cnt += item[j];
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt = 1;
    // cin >> tt;
    while (tt--) solve();

    return 0;
}
