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
int arr[1002][1002];
int p[1002][1002];
int st, en;

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fill(arr[i], arr[i] + n + 1, 1e9);
        arr[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;

        arr[a][b] = min(arr[a][b], cost);
        arr[b][a] = min(arr[b][a], cost);

        p[a][b] = b;
    }

    cin >> st >> en;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
                    p[i][j] = k;
                }
            }
        }
    }

    cout << arr[st][en] << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt = 1;
    // cin >> tt;
    while (tt--) solve();

    return 0;
}
