#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n;
int dp[50002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int minx = dp[i - 1] + 1;
        for (int j = 1; j * j <= i; j++) {
            minx = min(minx, dp[i - j * j]);
        }
        dp[i] = minx + 1;
    }

    cout << dp[n] << endl;
    return 0;
}
