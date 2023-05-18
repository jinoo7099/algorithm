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

    int t;
    cin >> t;

    ll n, m;
    cin >> n;

    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++) {
        ll k;
        cin >> k;
        a[i] = a[i - 1] + k;
    }

    cin >> m;
    vector<ll> b(m + 1);
    for (ll i = 1; i <= m; i++) {
        ll k;
        cin >> k;
        b[i] = b[i - 1] + k;
    }

    vector<ll> tmp_a;
    vector<ll> tmp_b;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j < i; j++) {
            tmp_a.push_back(a[i] - a[j]);
        }
    }

    for (ll i = 1; i <= m; i++) {
        for (ll j = 0; j < i; j++) {
            tmp_b.push_back(b[i] - b[j]);
        }
    }

    // for (int s : tmp_a)
    //     cout << s << endl;

    // for (int s : tmp_b)
    //     cout << s << endl;

    sort(tmp_a.begin(), tmp_a.end());
    sort(tmp_b.begin(), tmp_b.end());
    ll ans = 0;

    for (int i = 0; i < tmp_a.size(); i++) {
        ans += upper_bound(tmp_b.begin(), tmp_b.end(), t - tmp_a[i]) -
               lower_bound(tmp_b.begin(), tmp_b.end(), t - tmp_a[i]);
    }

    cout << ans << endl;
    return 0;
}
