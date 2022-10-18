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

ll getSum(ll x) {
    return x * (x + 1) / 2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, l;
    cin >> n >> l;

    for (ll i = l; i <= 100; i++) {
        ll p = n / i;
        ll s, e;
        ll sum;

        if (i % 2) {
            s = p - i / 2;
            e = p + i / 2;
        } else {
            s = p - i / 2 + 1;
            e = p + i / 2;
        }
        if (s < 0) break;

        sum = getSum(e) - getSum(s - 1);

        if (sum == n) {
            for (ll j = s; j <= e; j++) {
                cout << j << ' ';
            }
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
