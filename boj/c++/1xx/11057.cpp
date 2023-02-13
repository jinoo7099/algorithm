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

int d[1002][12];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < 10; i++) {
        d[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                d[i][j] += d[i - 1][k];
                d[i][j] %= 10007;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += d[n][i];
    }
    ans %= 10007;
    cout << ans << endl;

    return 0;
}
