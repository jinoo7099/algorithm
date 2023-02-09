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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    ll cnt = 0, mxval = -(1ll << 62) - 1, mxcnt = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || v[i - 1] == v[i])
            cnt++;
        else {
            if (mxcnt < cnt) {
                mxcnt = cnt;
                mxval = v[i - 1];
            }
            cnt = 1;
        }
    }
    if (mxcnt < cnt) mxval = v[n - 1];

    cout << mxval << endl;

    return 0;
}
