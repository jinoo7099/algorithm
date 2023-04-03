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

int n;
int ans = 1e9;
int arr[22][22];
int vis[22];

void solve(int cur, int st) {
    if (cur == n / 2) {
        int a, b;
        a = b = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (vis[i] == 1 and vis[j] == 1)
                    a += arr[i][j];
                if (vis[i] == 0 and vis[j] == 0)
                    b += arr[i][j];
            }
        }
        ans = min(ans, abs(a - b));
        return;
    }

    for (int i = st; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        solve(cur + 1, i + 1);
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    solve(0, 1);

    cout << ans << endl;

    return 0;
}
