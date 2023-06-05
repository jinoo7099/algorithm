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

const int nax = 2e5 + 5;

int n, m;
int par[nax];

int f(int x) {
    if (par[x] == x) return x;
    return par[x] = f(par[x]);
}

void u(int x, int y) {
    x = f(x);
    y = f(y);
    if (x == y) return;
    if (x > y) swap(x, y);
    par[y] = x;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        u(x, y);
    }
    int k;
    cin >> k;
    set<pii> bad;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x = f(x);
        y = f(y);
        if (x > y) swap(x, y);
        bad.insert({x, y});
    }

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x = f(x);
        y = f(y);
        if (x > y) swap(x, y);

        if (bad.count({x, y}))
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt = 1;
    while (tt--) solve();
    return 0;
}
