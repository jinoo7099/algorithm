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

int w, h, n;
int x, y;
map<pii, int> score;

void solve() {
    cin >> w >> h;
    cin >> n;
    vector<pii> v;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }

    vector<int> a, b;
    a.push_back(-1);
    b.push_back(-1);
    cin >> x;
    for (int i = 0; i < x; i++) {
        cin >> y;
        a.push_back(y);
    }
    cin >> x;
    for (int i = 0; i < x; i++) {
        cin >> y;
        b.push_back(y);
    }

    for (auto [x, y] : v) {
        int p1 = (int)(lower_bound(a.begin(), a.end(), x) - a.begin());
        int p2 = (int)(lower_bound(b.begin(), b.end(), y) - b.begin());
        score[{p1, p2}]++;
    }

    int minx = 1e9;
    int maxx = -1e9;

    if (score.size() != (int)a.size() * (int)b.size()) minx = 0;
    for (auto [_, sc] : score) {
        minx = min(minx, sc);
        maxx = max(maxx, sc);
    }

    cout << minx << ' ' << maxx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt = 1;
    while (tt--) solve();

    return 0;
}
