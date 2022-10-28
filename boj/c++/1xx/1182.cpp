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
int ans;
int n, k;

void solve(int cur, vector<int> a, int sum) {
    if (cur == a.size()) {
        if (sum == k) {
            ans += 1;
        }
        return;
    }

    solve(cur + 1, a, sum + a[cur]);

    solve(cur + 1, a, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    solve(0, a, 0);
    if (k == 0) ans -= 1;

    cout << ans << endl;

    return 0;
}
