#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;
const int nax = 1e5 + 5;

int par[nax];
int v, e;
tuple<int, int, int> edge[nax];

int f(int x) {
    if (par[x] == x) return x;
    return par[x] = f(par[x]);
}

bool u(int x, int y) {
    x = f(x);
    y = f(y);
    if (x == y) return 0;

    if (x > y) swap(x, y);
    par[y] = x;

    return 1;
}

void solve() {
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {c, a, b};
    }

    for (int i = 1; i <= v; i++) {
        par[i] = i;
    }

    sort(edge, edge + e);
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];

        if (!u(a, b)) continue;

        ans += cost;
        cnt++;

        if (cnt == v - 1) break;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt = 1;
    while (tt--) solve();

    return 0;
}
