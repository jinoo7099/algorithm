#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define X first
#define Y second

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int a, b;
int ans = 1e9;

void solve(ll x, int cnt) {
    if (x > 1e9) return;
    if (x == b && x < 1e9) {
        ans = min(ans, cnt);
        return;
    }
    solve(x * 2, cnt + 1);

    solve(x * 10 + 1, cnt + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;

    solve(a, 0);

    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans + 1 << endl;
    return 0;
}
