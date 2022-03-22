#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, d;
vector<pair<int, int>> arr[11111];
vector<int> dp(11111, 1e9);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[b].push_back({a, c});
    }

    dp[0] = 0;
    for (int i = 0; i <= d; i++) {
        dp[i] = min(dp[i], dp[i - 1] + 1);
        for (int j = 0; j < arr[i].size(); j++) {
            dp[i] = min(dp[i], dp[arr[i][j].first] + arr[i][j].second);
        }
    }

    cout << dp[d] << endl;
    return 0;
}
