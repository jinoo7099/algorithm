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

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    double k = round(n * 0.15);

    double sum = 0;
    for (int i = k; i < n - k; i++) {
        sum += a[i];
    }

    if ((n - 2 * k) == 0)
        cout << 0 << endl;
    else
        cout
            << round(sum / (n - 2 * k)) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt = 1;
    // cin >> tt;
    while (tt--) solve();

    return 0;
}
