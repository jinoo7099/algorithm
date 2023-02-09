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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<pair<string, int>, pair<int, int>>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi.fi >> v[i].fi.se >> v[i].se.fi >> v[i].se.se;
    }

    sort(v.begin(), v.end(), [&](pair<pair<string, int>, pii> a, pair<pair<string, int>, pii> b) {
        if (a.fi.se != b.fi.se) return a.fi.se > b.fi.se;
        if (a.se.fi != b.se.fi) return a.se.fi < b.se.fi;
        if (a.se.se != b.se.se) return a.se.se > b.se.se;
        return a.fi.fi < b.fi.fi;
    });

    for (auto a : v) {
        cout << a.fi.fi << endl;
    }
    return 0;
}
