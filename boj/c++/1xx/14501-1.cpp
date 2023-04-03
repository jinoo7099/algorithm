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

int dp[102];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = n; i >= 1; i--) {
        auto [t, p] = v[i];

        if (i + t > n + 1) {
            dp[i] = dp[i + 1];
        } else {
            dp[i] = max(dp[i + 1], dp[i + t] + p);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;

    return 0;
}
