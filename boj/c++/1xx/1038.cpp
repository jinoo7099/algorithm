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

ll res[1000001];
ll vis[12];
ll n, idx = 1;

void solve(ll origin) {
    res[idx++] = origin;

    for (int i = 0; i < 10; i++) {
        if (vis[i]) continue;
        if (origin % 10 <= i) continue;
        vis[i] = 1;
        solve(origin * 10 + i);
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    fill(res, res + 1000001, -1);

    res[0] = 0;
    for (int i = 1; i <= 9; i++) {
        vis[i] = 1;
        solve(i);
        vis[i] = 0;
    }

    sort(res, res + idx);

    cout << res[n] << endl;

    return 0;
}
